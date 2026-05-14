// 2026 Kristoffer

#include <stdio.h>
#include <string.h>
#include "../include/string-search.h"

void stringSearch(char*, char*);
int main(void)
{
    stringSearch("Heso Peso", "Pizza");
    stringSearch("cbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcb", "aaaaaaab");
    stringSearch("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab", "aaaaaaab");
    return 0;
}

void stringSearch(char* text, char* pattern)
{
    size_t count;
    size_t Tlen = strlen(text);
    size_t Plen = strlen(pattern);

    printf("=======================================\n");
    printf("|| -------------\n");
    printf("|| STRING SEARCH\n");
    printf("|| -------------\n||\n");

    printf("|| Text: %s\n", text);
    printf("|| Pattern: %s\n||\n", pattern);

    int i = bruteForce(text, Tlen, pattern, Plen, &count);
    printf("|| Text length = %zu\n", Tlen);
    printf("|| Pattern length = %zu\n", Plen);

    if (i == -1) {
        printf("|| Failed to find a match\n");
    } else {
        printf("|| Found %s at index %d\n", pattern, i);
    }

    printf("|| Basic operations = %zu\n", count);
    printf("=======================================\n\n");
}
