// 2026 Kristoffer
//
// Implementation of the Boyer-Moore algorithm

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#include "../include/string-search.h"

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
int bruteForce(char *text, size_t tlength, char *pattern, size_t plength, size_t *count)
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

/* Boyer-Moore
Implements Boyer-Moore’s algorithm for string matching
Input: Pattern P[0..m − 1] and text T[0..n − 1]
Output: The index of the left end of the first matching substring or −1 if there are no matches

TODO: Pseudocode is currently just shows Horspool. Update to reflect Boyer-Moore

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
int boyerMoore(char *text, size_t tlength, char *pattern, size_t plength, size_t *count)
{
    // TODO: Upgrade it from just Horspool to Boyer-Moore.
    // TODO: Test if Boyer-Moore upgrade works.
    // TODO: Add basic operations counter.
    int *table = shiftTable(pattern);
    if (table == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
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
            free(table);
            return end - plength + 1;
        } else end += table[(unsigned char)text[end]];
    }

    free(table);
    return -1;
}

/* Shift table
Fills the shift table used by Horspool’s and Boyer-Moore algorithms
Input: Pattern P[0..m − 1] and an alphabet of possible characters
Output: Table[0..size − 1] indexed by the alphabet’s characters and filled with shift sizes computed by formula (7.1)

for i <- 0 to size − 1 do Table[i] <- m
for j <- 0 to m − 2 do Table[P[j]] <- m − 1 − j
return Table */
int* shiftTable(char *pattern)
{
    int *table = malloc(ALPHABET * sizeof(int));
    if (table == NULL) return NULL;

    size_t pLen = strlen(pattern);

    // Initialize all character skips to the length of the pattern.
    for (size_t i = 0; i < ALPHABET; i++) {
        table[i] = pLen;
    }

    // Adjust the skips of the characters that are in the pattern to match how far from the end they are.
    for (size_t i = 0; i < pLen - 1; i++) {
        table[(unsigned char)pattern[i]] = pLen - 1 - i;
    }
    return table;
}
