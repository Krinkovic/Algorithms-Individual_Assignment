#include <limits.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET (UCHAR_MAX + 1)

size_t badSymbolShift(const char* const text, size_t matched, size_t end, const size_t *shiftTable);
size_t* shiftTable(const char *const pattern);
int max(int a, int b);

int main()
{
    char *pattern = "barber";
    size_t *table = shiftTable(pattern);
    size_t badsymbol = badSymbolShift("ooooseroooo", 2, 6, table);
    printf("%zu\n", badsymbol);
}

size_t* shiftTable(const char *const pattern)
{
    size_t *table = malloc(ALPHABET * sizeof(table));
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

/* Bad Symbol Shift
If some characters k > 0 have been matched before a mismatch, shift the pattern based on it's shift table value table[c] - k characters.
If result is <= 0, shift 1.*/
size_t badSymbolShift(const char* const text, size_t matched, size_t end, const size_t *shiftTable)
{
    char mismatch = text[end - matched];
    printf("Mismatched C: %c\n", mismatch); // TODO remove this
    return max((int)(shiftTable[(unsigned char)mismatch] - matched), 1);
}

int max(int a, int b)
{
    if (a >= b) return a;
    else return b;
}
