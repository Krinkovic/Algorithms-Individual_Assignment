// 2026 Kristoffer
//
// Implementation of the Boyer-Moore algorithm

#include <stdlib.h>
#include "../include/string-search.h"

//Implements brute-force string matching
//Input: An array T[0..n − 1] of n characters representing a text and
//
// an array P[0..m − 1] of m characters representing a pattern
//Output: The index of the first character in the text that starts a
//
// matching substring or −1 if the search is unsuccessful
//
// for i <- 0 to n − m do
    // j <- 0
    // while j < m and P[j] = T[i + j] do
        // j <- j + 1
    // if j = m return i
// return −1
int bruteForce(char* text, size_t tlength, char* pattern, size_t plength)
{
    for (int i = 0; i <= tlength - plength; i++) {
        int j = 0;
        while (j < plength && pattern[j] == text[i + j]) {
            j = j + 1;
        }
        if (j == plength) return i;
    }
    return -1;
}

int boyerMoore(char* text, size_t tlength, char* pattern, size_t plength)
{
    int i;
    return i;
}
