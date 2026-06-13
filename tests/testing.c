// 2026 Kristoffer

#include <complex.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include "string-search.h"

void printResults(char*, int (char*, size_t, char*, size_t, size_t*), char*, size_t, char*, size_t, size_t*);

int main(void)
{
    char *text = "bcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcb";
    size_t tLen = strlen(text);
    char *pattern = "Pizza";
    size_t pLen = strlen(pattern);
    size_t count = 0;

    printResults("Brute Force", bruteForce, text, tLen, pattern, pLen, &count);
    printResults("Horspool", horspool, text, tLen, pattern, pLen, &count);
    printResults("Boyer-Moore", boyerMoore, text, tLen, pattern, pLen, &count);

    text = "bcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcb";
    tLen = strlen(text);
    pattern = "aaaaaaab";
    pLen = strlen(pattern);

    printResults("Brute Force", bruteForce, text, tLen, pattern, pLen, &count);
    printResults("Horspool", horspool, text, tLen, pattern, pLen, &count);
    printResults("Boyer-Moore", boyerMoore, text, tLen, pattern, pLen, &count);

    text = "aaaabaaabaaabaabaaabaaabaaabaaabaaabaaabaaabaaabaaaaaaaaaaaab";
    tLen = strlen(text);
    pattern = "aaaaaaab";
    pLen = strlen(pattern);

    printResults("Brute Force", bruteForce, text, tLen, pattern, pLen, &count);
    printResults("Horspool", horspool, text, tLen, pattern, pLen, &count);
    printResults("Boyer-Moore", boyerMoore, text, tLen, pattern, pLen, &count);

    return 0;
}

void printResults(char *name, int algorithm(char*, size_t, char*, size_t, size_t*), char *text, size_t tLen, char *pattern, size_t pLen, size_t *counter)
{
    printf("=======================================\n");
    printf("|| -------------\n");
    printf("|| %s\n", name);
    printf("|| -------------\n");
    printf("||\n");
    printf("|| Text: %s\n", text);
    printf("|| Pattern: %s\n", pattern);
    printf("||\n");
    printf("|| Text length = %zu\n", tLen);
    printf("|| Pattern length = %zu\n", pLen);
    printf("||\n");
    *counter = 0;
    int result = algorithm(text, tLen, pattern, pLen, counter);
    if (result == -1) {
        printf("|| Failed to find a match\n");
    } else {
        printf("|| Found %s at index %d\n", pattern,result);
    }
    printf("|| Basic operations = %zu\n", *counter);
    printf("||\n");
    printf("=======================================\n\n");
}
