#include <stdio.h>
#include <string.h>
#include <limits.h>

#define ALPHABET (UCHAR_MAX + 1)

// preprocessing for strong good suffix rule
void preprocess_strong_suffix(int *shift, int *bpos, char *pat, int m)
{
    // m is the length of pattern
    int i=m, j=m+1;
    bpos[i]=j;

    while(i>0)
    {
        /*if character at position i-1 is not equivalent to
          character at j-1, then continue searching to right
          of the pattern for border */
        while(j<=m && pat[i-1] != pat[j-1])
        {
            /* the character preceding the occurrence of t in
               pattern P is different than the mismatching character in P,
               we stop skipping the occurrences and shift the pattern
               from i to j */
            if (shift[j]==0)
                shift[j] = j-i;

            //Update the position of next border
            j = bpos[j];
        }
        /* p[i-1] matched with p[j-1], border is found.
           store the  beginning position of border */
        i--;j--;
        bpos[i] = j;
    }
}

//Preprocessing for case 2
void preprocess_case2(int *shift, int *bpos, char *pat, int m)
{
    int i, j;
    j = bpos[0];
    for(i=0; i<=m; i++)
    {
        /* set the border position of the first character of the pattern
           to all indices in array shift having shift[i] = 0 */
        if(shift[i]==0)
            shift[i] = j;

        /* suffix becomes shorter than bpos[0], use the position of
           next widest border as value of j */
        if (i==j)
            j = bpos[j];
    }
}


void search(char *text, char *pat)
{
    // s is shift of the pattern with respect to text
    int s=0, j;
    int m = strlen(pat);
    int n = strlen(text);

    int count = 0;

    // Adjust the skips of the characters that are in the pattern to match how far from the end they are.
    int badCharShift[ALPHABET] = {0}, bpos[m+1], goodSufShift[m+1];
        for (size_t i = 0; i < m - 1; i++) {
            badCharShift[(unsigned char)pat[i]] = m - 1 - i;
    }

    //initialize all occurrence of goodSufShift to 0
    for(int i=0;i<m+1;i++) goodSufShift[i]=0;

    //do preprocessing
    preprocess_strong_suffix(goodSufShift, bpos, pat, m);
    preprocess_case2(goodSufShift, bpos, pat, m);

    while(s <= n-m)
    {

        j = m-1;

        /* Keep reducing index j of pattern while characters of
             pattern and text are matching at this shift s*/
        while(j >= 0 && pat[j] == text[s+j]) {
            count++; // Count the basic operation.
            j--;
        }

        if (j >= 0) count++; // Count the failed comparison that broke the loop, if any.
        /* If the pattern is present at the current shift, then index j

             will become -1 after the above loop */
        if (j<0)
        {
            printf("pattern occurs at shift = %d\n", s);
            printf("Operations: %d\n", count);
            s += goodSufShift[0];
        }
        else
            /*pat[i] != pat[s+j] so shift the pattern
              shift[j+1] times  */
            s += goodSufShift[j+1];
    }

}

int main()
{
    char text[] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
    char pat[] = "aaaaab";
    search(text, pat);
    return 0;
}
