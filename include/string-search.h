// 2026 Kristoffer

#ifndef BOYER_MOORE_H
#define BOYER_MOORE_H

#include <stddef.h>
#include <stdlib.h>

#define ALPHABET (UCHAR_MAX + 1)

// Implements brute-force string matching
// Input: An array T [0..n − 1] of n characters representing a text and an array P [0..m − 1] of m characters representing a pattern
// Output: The index of the first character in the text that starts a matching substring or −1 if the search is unsuccessful
int bruteForce(const char *const text, size_t tlength, const char *const pattern, size_t plength, size_t *const count);

// Implements Boyer-Moore’s algorithm for string matching
// Input: Pattern P [0..m − 1] and text T [0..n − 1]
// Output: The index of the left end of the first matching substring or −1 if there are no matches
int boyerMoore(const char *const text, size_t tlength, const char *const pattern, size_t plength, size_t *const count);

// Fills the shift table used by Horspool’s and Boyer-Moore algorithms
// Input: Pattern P [0..m − 1] and an alphabet of possible characters
// Output: Table[0..size − 1] indexed by the alphabet’s characters and filled with shift sizes computed by formula (7.1)
int* shiftTable(const char *const pattern);

#endif
