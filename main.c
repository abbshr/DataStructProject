#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <time.h>

#define M 50000
#define N 50000

void KMP(char B[], char A[], int n, int m)
{
    /* preprocess P */
    int P[M];
    P[0] = -1;
    int j = -1;
    int i;
    for (i = 1; i < m; i++)
    {
        while (j >= 0 && B[j + 1] != B[i])
            j = P[j];
        if (B[j + 1] == B[i])
            j++;
        P[i] = j;
    }

    /* KMP */
    j = -1;
    for (i = 0; i < n; i++)
    {
        while (j >= 0 && B[j + 1] != A[i])
            j = P[j];
        if (B[j + 1] == A[i])
            j++;
        if (j == m - 1) 
        {
            printf("KMP 位置: %d\n", i - m + 2);
            j = P[j];
        }
    }
}

void Rabin_Karp(char P[], char T[], int n, int m)
{
    int d = 10; 
    int q = 13;
    int h = 1;
    int p = 0;
    int t = 0;
    int i, s, j;

    for (i = 0; i < m - 1; i++)
        h = ( h * d );

    /* preprecess: get hash t & p */
    for (i = 0; i < m; i++)
    {
        p = (d * p + P[i]);
        t = (d * t + T[i]); 
    }

    /* rabin-karp */
    for (s = 0; s < n - m; s++)
    {
        if (p == t)
        {
            for (j = 0; j < m; j++)
                if (T[s + j] != P[j])
                    break;       
            if (j == m)
                printf("Rabin-Karp 位置: %d\n", s + 1);
        }
        if (s < n - m)
            t = (d * (t - T[s] * h) + T[s + m]);
    }
}

void Naive_Match(char P[], char T[], int n, int m)
{
    int i, j;
    for (i = 0; i < n - m + 1; i++)
    {
        for (j = 0; j < m; j++)
            if (P[j] != T[i + j])
                break;
        if (j == m)
            printf("Naive 位置: %d\n", i + 1);
    }
}


int main(int argc, char const *argv[])
{
    double timeuse;
    char str[N], p[M];

    /* read from file s*/
    /* string length: 1301 */
    FILE* fp = NULL;
    fp = fopen("test", "r");
    while (fscanf(fp, "%s", str) != -1);
    int n = strlen(str);

    /* input pattern str */ 
    printf("输入模式串：\n");
    scanf("%s", p);
    int m = strlen(p);

    /* Naive Match */
    Naive_Match(p, str, n, m);

    /* Rabin-Karp */	
    Rabin_Karp(p, str, n, m);

    /* KMP */
    KMP(p, str, n, m);
	
    return 0;
}