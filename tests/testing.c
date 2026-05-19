// 2026 Kristoffer

#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include "../include/string-search.h"

void stringSearch(const char *const, const char *const);
void runAlgorithms(const char* const text, const char* const pattern, int (*algorithms[3])(const char* const, size_t, const char* const, size_t, size_t*));
int main(void)
{
    int (*algorithms[3])(const char* const, size_t, const char* const, size_t, size_t* const) = {bruteForce, horspool, boyerMoore};
    const char* const texts[] = {
        "heso Peso",
        "bcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcb",
        "aaaabaaabaaabaabaaabaaabaaabaaabaaabaaabaaabaaabaaaaaaaaaaaab",
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab"
    };
    const char* const patterns[]= {
        "Pizza",
        "aaaaaaab",
        "aaaaaaab",
        "aaaaaaab"
    };

    for (int i = 0; i < 3; i++) {
        runAlgorithms(texts[i], patterns[i], algorithms);
    }
    return 0;
}

void runAlgorithms(const char* const text, const char* const pattern, int (*algorithms[3])(const char* const, size_t, const char* const, size_t, size_t*))
{
    size_t count;
    size_t Tlen = strlen(text);
    size_t Plen = strlen(pattern);
    char *fNames[] = {"Brute Force", "Horspool", "Boyer-Moore"};

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
    for (int i = 0; i < 3; i++) {
        printf("|| %s:\n", fNames[i]);
        int result = algorithms[i](text, Tlen, pattern, Plen, &count);
        if (result == -1) {
            printf("|| Failed to find a match\n");
        } else {
            printf("|| Found %s at index %d\n", pattern,result);
        }
        printf("|| Basic operations = %zu\n", count);
        printf("||\n");
    }
    printf("=======================================\n\n");
}
