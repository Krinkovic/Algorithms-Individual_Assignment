// 2026 Kristoffer
//
// Implementation of the Boyer-Moore algorithm

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#include "string-search.h"

int max(int a, int b);

/* Brute force matching
Implements brute-force string matching
Input: An array T[0..n − 1] of n characters representing a text and an array P[0..m − 1] of m characters representing a pattern
Output: The index of the first character in the text that starts a matching substring or −1 if the search is unsuccessful

for i <- 0 to n − m do
    j <- 0
    while j < m and P[j] = T[i + j] do
        j <- j + 1
    if j = m return i
    return −1 */
int bruteForce(
    char *text,
    size_t tlength,
    char *pattern,
    size_t plength,
    size_t *count)
{
    *count = 0; // Basic operations counter.

    // Start at zero and move to the end minus the length of the pattern.
    for (size_t i = 0; i <= tlength - plength; i++) {
        size_t j = 0;

        // When a letter matches, move to check the next one.
        while (j < plength && pattern[j] == text[i + j]) {
            (*count) ++; // Count the comparisons.
            j++;
        }
        if (j < plength) (*count)++; // Count the failed comparison that broke the loop, if any.

        if (j == plength) return i; // Match found.
    }
    return -1;
}

/* Horspool
Implements Boyer-Moore’s algorithm for string matching
Input: Pattern P[0..m − 1] and text T[0..n − 1]
Output: The index of the left end of the first matching substring or −1 if there are no matches

ShiftTable(P[0..m − 1]) // generate Table of shifts
i <- m − 1 // position of the pattern’s right end
while i <= n − 1 do
    k <- 0 // number of matched characters
    while k <= m − 1 and P[m − 1 − k] = T[i − k] do
        k <- k + 1
    if k = m
        return i − m + 1
    else i <- i + Table[T[i]]
return −1 */
int horspool(
    char *text,
    size_t tlength,
    char *pattern,
    size_t plength,
    size_t *count)
{

    // Create shift table and initialize all character skips to the length of the pattern.
    size_t shiftTable[ALPHABET];
    for (size_t i = 0; i < ALPHABET; i++) shiftTable[i] = plength;

    // Adjust the skips of the characters that are in the pattern to match how far from the end they are.
    for (size_t i = 0; i < plength - 1; i++) {
        shiftTable[(unsigned char)pattern[i]] = plength - 1 - i;
    }

    size_t end = plength - 1; // Rightmost end of the pattern.
    *count = 0; // Basic operations counter.

    // Loop while the pattern has not passed the text.
    while (end < tlength) {
        size_t matched = 0; // Number of characters matched.

        // Count number of matched characters in current position.
        while (matched < plength && pattern[plength - 1 - matched] == text[end - matched]) {
            (*count)++; // Count the basic operation.
            matched++;
        }
        if (matched < plength) (*count)++; // Count the failed comparison that broke the loop, if any.

        // If the whole pattern has been found, return index of first character. Else move pattern according to the shift table.
        if (matched == plength) {
            return end - plength + 1;
        } else end += shiftTable[(unsigned char)text[end]];
    }

    return -1;
}

// Boyer-Moore
int boyerMoore(
    char *text,
    size_t tlength,
    char *pattern,
    size_t plength,
    size_t *count)
{
    // Create the Bad Character shift table and initialize all character skips to the length of the pattern.
    size_t badCharShift[ALPHABET];
    for (size_t i = 0; i < ALPHABET; i++) badCharShift[i] = plength;

    // Adjust the skips of the characters that are in the pattern to match how far from the end they are.
    for (size_t i = 0; i < plength - 1; i++) {
        badCharShift[(unsigned char)pattern[i]] = plength - 1 - i;
    }

    // Create the Good Suffix shift table
    int goodSuffixShift[plength + 1];
    int bpos[plength + 1];
    memset(goodSuffixShift, 0, (plength + 1) * sizeof(int));

    preprocess_strong_suffix(goodSuffixShift, bpos, pattern, plength);
    preprocess_case2(goodSuffixShift, bpos, plength);

    int end = plength - 1; // Rightmost end of the pattern.
    *count = 0; // Basic operations counter.

    // Loop while the pattern has not passed the text.
    while (end < (int) tlength) {
        int matched = 0; // Number of characters matched.

        // Count number of matched characters in current position.
        while (matched < (int) plength && pattern[plength - 1 - matched] == text[end - matched]) {
            (*count)++; // Count the basic operation.
            matched++;
        }
        if (matched < (int) plength) (*count)++; // Count the failed comparison that broke the loop, if any.

        // If the whole pattern has been found, return index of first character. Else move pattern according to the shift table.
        if (matched == (int) plength) {
            return end - (int) plength + 1;
        } else end += max((int)badCharShift[(unsigned char)text[end]], goodSuffixShift[plength - matched]);
    }

    return -1;
}

// I have tried and tried to actually understand how to implement this algorithm, but I just don't get it.
// I have read multiple articles trying to step by step explain it, I have drawn up visual aids, but nothing has helped me get it.
// So I give up and will just use it without understanding it.
// This is just copy pasted straight from https://www.geeksforgeeks.org/dsa/boyer-moore-algorithm-good-suffix-heuristic/.
// preprocessing for strong good suffix rule
void preprocess_strong_suffix(int *shift, int *bpos, char *pat, int m)
{
    // m is the length of pattern
    int i=m, j=m+1;
    bpos[i]=j;

    while(i>0)
    {
        /*if character at position i-1 is not equivalent to
          character at j-1, then continue searching to right
          of the pattern for border */
        while(j<=m && pat[i-1] != pat[j-1])
        {
            /* the character preceding the occurrence of t in
               pattern P is different than the mismatching character in P,
               we stop skipping the occurrences and shift the pattern
               from i to j */
            if (shift[j]==0)
                shift[j] = j-i;

            //Update the position of next border
            j = bpos[j];
        }
        /* p[i-1] matched with p[j-1], border is found.
           store the  beginning position of border */
        i--;j--;
        bpos[i] = j;
    }
}

//Preprocessing for case 2
void preprocess_case2(int *table, int *bpos, int plength)
{
    int i, j;
    j = bpos[0];
    for(i=0; i<=plength; i++)
    {
        /* set the border position of the first character of the pattern
           to all indices in array shift having shift[i] = 0 */
        if(table[i]==0)
            table[i] = j;

        /* suffix becomes shorter than bpos[0], use the position of
           next widest border as value of j */
        if (i==j)
            j = bpos[j];
    }
}

void search(char *text, char *pat)
{
    // s is shift of the pattern with respect to text
    int s=0, j;
    int m = strlen(pat);
    int n = strlen(text);

    int bpos[m+1], shift[m+1];

    //initialize all occurrence of shift to 0
    for(int i=0;i<m+1;i++) shift[i]=0;

    //do preprocessing
    preprocess_strong_suffix(shift, bpos, pat, m);
    preprocess_case2(shift, bpos, m);

    while(s <= n-m)
    {

        j = m-1;

        /* Keep reducing index j of pattern while characters of
             pattern and text are matching at this shift s*/
        while(j >= 0 && pat[j] == text[s+j])
            j--;

        /* If the pattern is present at the current shift, then index j
             will become -1 after the above loop */
        if (j<0)
        {
            printf("pattern occurs at shift = %d\n", s);
            s += shift[0];
        }
        else
            /*pat[i] != pat[s+j] so shift the pattern
              shift[j+1] times  */
            s += shift[j+1];
    }
}

int max(int a, int b)
{
    if (a > b) return a;
    return b;
}
