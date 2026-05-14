// 2026 Kristoffer

#include <stdio.h>
#include <string.h>
#include "../include/string-search.h"

int main(void)
{
    size_t count;
    char* T = "Heso Peso Pesto";    ;
    size_t Tlen = strlen(T);
    char* P = "august";
    size_t Plen = strlen(P);

    int i = bruteForce(T, Tlen, P, Plen, &count);
    printf("Text length = %zu\n", Tlen);
    printf("Pattern length = %zu\n", Plen);

    if (i == -1) {
        printf("Failed to find a match\n");
    } else {
        printf("Found %s at index %d\n", P, i);
    }

    printf("Basic operations = %zu\n", count);
    return 0;
}
