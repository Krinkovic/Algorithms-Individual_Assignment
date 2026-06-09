#include "string-search.h"
#include <stdatomic.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

void printResults(int boyer(char*, size_t, char*, size_t, size_t*), char *text, size_t tLen, char *pattern, size_t pLen, size_t *counter);

int main()
{
    // search(text, pat);
    char *text = "bcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcb";
    size_t tLen = strlen(text);
    char *pattern = "Pizza";
    size_t pLen = strlen(pattern);
    size_t count = 0;
    int result;


    printResults(boyerMoore, text, tLen, pattern, pLen, &count);

    text = "bcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcb";
    tLen = strlen(text);
    pattern = "aaaaaaab";
    pLen = strlen(pattern);
    count = 0;

    printResults(boyerMoore, text, tLen, pattern, pLen, &count);

    text = "aaaabaaabaaabaabaaabaaabaaabaaabaaabaaabaaabaaabaaaaaaaaaaaab";
    tLen = strlen(text);
    pattern = "aaaaaaab";
    pLen = strlen(pattern);
    count = 0;

    printResults(boyerMoore, text, tLen, pattern, pLen, &count);

    text = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
    tLen = strlen(text);
    pattern = "aaaaaaab";
    pLen = strlen(pattern);
    count = 0;

    printResults(boyerMoore, text, tLen, pattern, pLen, &count);

    return 0;
}

void printResults(int boyer(char*, size_t, char*, size_t, size_t*), char *text, size_t tLen, char *pattern, size_t pLen, size_t *counter)
{
    printf("=======================================\n");
    printf("|| -------------\n");
    printf("|| STRING SEARCH\n");
    printf("|| -------------\n");
    printf("||\n");
    printf("|| Text: %s\n", text);
    printf("|| Pattern: %s\n", pattern);
    printf("||\n");
    printf("|| Text length = %zu\n", tLen);
    printf("|| Pattern length = %zu\n", pLen);
    printf("||\n");
    printf("|| Boyer-Moore:\n");
    int result = boyerMoore(text, tLen, pattern, pLen, counter);
    if (result == -1) {
        printf("|| Failed to find a match\n");
    } else {
        printf("|| Found %s at index %d\n", pattern,result);
    }
    printf("|| Basic operations = %zu\n", *counter);
    printf("||\n");
    printf("=======================================\n\n");
}
