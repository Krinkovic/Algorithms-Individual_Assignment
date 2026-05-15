// 2026 Kristoffer

#include <stdio.h>
#include <string.h>
#include "../include/string-search.h"

void stringSearch(char*, char*);
int main(void)
{
    stringSearch("Heso Peso", "Pizza");
    stringSearch("bcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcb", "aaaaaaab");
    stringSearch("aaaabaaabaaabaabaaabaaabaaabaaabaaabaaabaaabaaabaaaaaaaaaaaab", "aaaaaaab");
    stringSearch("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab", "aaaaaaab");
    return 0;
}

void stringSearch(char* text, char* pattern)
{
    size_t count1;
    size_t count2;
    size_t Tlen = strlen(text);
    size_t Plen = strlen(pattern);
    int i = bruteForce(text, Tlen, pattern, Plen, &count1);
    int j = boyerMoore(text, Tlen, pattern, Plen, &count2);

    printf("=======================================\n");
    printf("|| -------------\n");
    printf("|| STRING SEARCH\n");
    printf("|| -------------\n");
    printf("||\n");
    printf("|| Text: %s\n", text);
    printf("|| Pattern: %s\n", pattern);
    printf("||\n");
    printf("|| Text length = %zu\n", Tlen);
    printf("|| Pattern length = %zu\n", Plen);
    printf("||\n");
    printf("|| Brute Force:\n");
    if (i == -1) {
        printf("|| Failed to find a match\n");
    } else {
        printf("|| Found %s at index %d\n", pattern, i);
    }
    printf("|| Basic operations = %zu\n", count1);
    printf("||\n");
    printf("|| Boyer-Moore:\n");
    if (j == -1) {
        printf("|| Failed to find a match\n");
    } else {
        printf("|| Found %s at index %d\n", pattern, i);
    }
    printf("|| Basic operations = %zu\n", count2);
    printf("=======================================\n\n");
}
