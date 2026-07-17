// 2026 Kristoffer

#include <complex.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include "string-search.h"

void printResults(char*, int (char*, size_t, char*, size_t, size_t*), char*, size_t, char*, size_t, size_t*);

int main(void)
{
    char *text = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    size_t tLen = strlen(text);
    char *pattern = "aaaaaab";
    size_t pLen = strlen(pattern);
    size_t count = 0;

    printResults("Brute Force", bruteForce, text, tLen, pattern, pLen, &count);
    printResults("Horspool", horspool, text, tLen, pattern, pLen, &count);
    printResults("Boyer-Moore", boyerMoore, text, tLen, pattern, pLen, &count);

    text = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    tLen = strlen(text);
    pattern = "baaaaaa";
    pLen = strlen(pattern);

    printResults("Brute Force", bruteForce, text, tLen, pattern, pLen, &count);
    printResults("Horspool", horspool, text, tLen, pattern, pLen, &count);
    printResults("Boyer-Moore", boyerMoore, text, tLen, pattern, pLen, &count);

    text = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    tLen = strlen(text);
    pattern = "aaabaaa";
    pLen = strlen(pattern);

    printResults("Brute Force", bruteForce, text, tLen, pattern, pLen, &count);
    printResults("Horspool", horspool, text, tLen, pattern, pLen, &count);
    printResults("Boyer-Moore", boyerMoore, text, tLen, pattern, pLen, &count);

    text = "aaabaaabaaabaaabaaabaaabaaabaaabaaabaaabaaabaaabaaabaaabaaaba";
    tLen = strlen(text);
    pattern = "aaaaaab";
    pLen = strlen(pattern);

    printResults("Brute Force", bruteForce, text, tLen, pattern, pLen, &count);
    printResults("Horspool", horspool, text, tLen, pattern, pLen, &count);
    printResults("Boyer-Moore", boyerMoore, text, tLen, pattern, pLen, &count);

    text = "aabaabaabaabaabaabaabaabaabaabaabaabaabaabaabaabaabaabaabaaba";
    tLen = strlen(text);
    pattern = "aaabaaa";
    pLen = strlen(pattern);

    printResults("Brute Force", bruteForce, text, tLen, pattern, pLen, &count);
    printResults("Horspool", horspool, text, tLen, pattern, pLen, &count);
    printResults("Boyer-Moore", boyerMoore, text, tLen, pattern, pLen, &count);

    text = "aaabaaabaaabaaabaaabaaabaaabaaabaaabaaabaaabaaabaaabaaabaaaba";
    tLen = strlen(text);
    pattern = "baaaaaa";
    pLen = strlen(pattern);

    printResults("Brute Force", bruteForce, text, tLen, pattern, pLen, &count);
    printResults("Horspool", horspool, text, tLen, pattern, pLen, &count);
    printResults("Boyer-Moore", boyerMoore, text, tLen, pattern, pLen, &count);

    text = "abababababababababababababababababababababababababababacababa";
    tLen = strlen(text);
    pattern = "cababab";
    pLen = strlen(pattern);

    printResults("Brute Force", bruteForce, text, tLen, pattern, pLen, &count);
    printResults("Horspool", horspool, text, tLen, pattern, pLen, &count);
    printResults("Boyer-Moore", boyerMoore, text, tLen, pattern, pLen, &count);

    text = "ababababababababababababababababababababababababababababababa";
    tLen = strlen(text);
    pattern = "abababc";
    pLen = strlen(pattern);

    printResults("Brute Force", bruteForce, text, tLen, pattern, pLen, &count);
    printResults("Horspool", horspool, text, tLen, pattern, pLen, &count);
    printResults("Boyer-Moore", boyerMoore, text, tLen, pattern, pLen, &count);

    text = "ababababababababababababababababababababababababababababababa";
    tLen = strlen(text);
    pattern = "abacaba";
    pLen = strlen(pattern);

    printResults("Brute Force", bruteForce, text, tLen, pattern, pLen, &count);
    printResults("Horspool", horspool, text, tLen, pattern, pLen, &count);
    printResults("Boyer-Moore", boyerMoore, text, tLen, pattern, pLen, &count);

    text = "1101010010110010101010011010010111001011010101010101001010100";
    tLen = strlen(text);
    pattern = "11111";
    pLen = strlen(pattern);

    printResults("Brute Force", bruteForce, text, tLen, pattern, pLen, &count);
    printResults("Horspool", horspool, text, tLen, pattern, pLen, &count);
    printResults("Boyer-Moore", boyerMoore, text, tLen, pattern, pLen, &count);

    text = "0000100001000000010000000010000000100000010000000000000000000";
    tLen = strlen(text);
    pattern = "0101010";
    pLen = strlen(pattern);

    printResults("Brute Force", bruteForce, text, tLen, pattern, pLen, &count);
    printResults("Horspool", horspool, text, tLen, pattern, pLen, &count);
    printResults("Boyer-Moore", boyerMoore, text, tLen, pattern, pLen, &count);

text = "It was the best of times, it was the worst of times, it was the age of wisdom, it was the age of foolishness, it was the epoch of belief, it was the epoch of incredulity, it was the season of Light, it was the season of Darkness, it was the spring of hope, it was the winter of despair, we had everything before us, we had nothing before us, we were all going direct to Heaven, we were all going direct the other way-in short, the period was so far like the present period, that some of its noisiest authorities insisted on its being received, for good or for evil, in the superlative degree of comparison only. There were a king with a large jaw and a queen with a plain face, on the throne of England; there were a king with a large jaw and a queen with a fair face, on the throne of France. In both countries it was clearer than crystal to the lords of the State preserves of loaves and fishes, that things in general were settled for ever. It was the year of Our Lord one thousand seven hundred and seventy-five. Spiritual revelations were conceded to England at that favoured period, as at this. Mrs. Southcott had recently attained her five-and-twentieth blessed birthday, of whom a prophetic private in the Life Guards had heralded the sublime appearance by announcing that arrangements were made for the swallowing up of London and Westminster. Even the Cock-lane ghost had been laid only a round dozen of years, after rapping out its messages, as the spirits of this very year last past (supernaturally deficient in originality) rapped out theirs. Mere messages in the earthly order of events had lately come to the English Crown and People, from a congress of British subjects in America: which, strange to relate, have proved more important to the human race than any communications yet received through any of the chickens of the Cock-lane brood.";
    tLen = strlen(text);
    pattern = "spirits";
    pLen = strlen(pattern);

    printResults("Brute Force", bruteForce, text, tLen, pattern, pLen, &count);
    printResults("Horspool", horspool, text, tLen, pattern, pLen, &count);
    printResults("Boyer-Moore", boyerMoore, text, tLen, pattern, pLen, &count);

text = "It was the best of times, it was the worst of times, it was the age of wisdom, it was the age of foolishness, it was the epoch of belief, it was the epoch of incredulity, it was the season of Light, it was the season of Darkness, it was the spring of hope, it was the winter of despair, we had everything before us, we had nothing before us, we were all going direct to Heaven, we were all going direct the other way-in short, the period was so far like the present period, that some of its noisiest authorities insisted on its being received, for good or for evil, in the superlative degree of comparison only. There were a king with a large jaw and a queen with a plain face, on the throne of England; there were a king with a large jaw and a queen with a fair face, on the throne of France. In both countries it was clearer than crystal to the lords of the State preserves of loaves and fishes, that things in general were settled for ever. It was the year of Our Lord one thousand seven hundred and seventy-five. Spiritual revelations were conceded to England at that favoured period, as at this. Mrs. Southcott had recently attained her five-and-twentieth blessed birthday, of whom a prophetic private in the Life Guards had heralded the sublime appearance by announcing that arrangements were made for the swallowing up of London and Westminster. Even the Cock-lane ghost had been laid only a round dozen of years, after rapping out its messages, as the spirits of this very year last past (supernaturally deficient in originality) rapped out theirs. Mere messages in the earthly order of events had lately come to the English Crown and People, from a congress of British subjects in America: which, strange to relate, have proved more important to the human race than any communications yet received through any of the chickens of the Cock-lane brood.";
    tLen = strlen(text);
    pattern = "with";
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
