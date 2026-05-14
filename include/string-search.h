// 2026 Kristoffer

#ifndef BOYER_MOORE_H
#define BOYER_MOORE_H

#include <stdlib.h>

//Implements brute-force string matching
//Input: An array T [0..n − 1] of n characters representing a text and
//
// an array P [0..m − 1] of m characters representing a pattern
//Output: The index of the first character in the text that starts a
//
// matching substring or −1 if the search is unsuccessful
int bruteForce(char* text, size_t tlength, char* pattern, size_t plength);

int boyerMoore(char* text, size_t tlength, char* pattern, size_t plength);

#endif
