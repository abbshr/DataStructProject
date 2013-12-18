#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <time.h>

#define M 30
#define N 4000000

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

int main(int argc, char const *argv[])
{
    clock_t t1, t2;

    char str[N], p[M];

    /* read from file s*/
    /* string length: <= 400W */
    FILE* fp = NULL;
    fp = fopen("test", "r");
    while (fscanf(fp, "%s", str) != -1);
    int n = strlen(str);

    /* input pattern str */ 
    printf("输入模式串：\n");
    scanf("%s", p);
    int m = strlen(p);

    /* Rabin-Karp */    
    t1 = clock();
    Rabin_Karp(p, str, n, m);
    t2 = clock();
    printf("Rabin-Karp匹配时间（ms）：%lf\n", (double)(t2 - t1));

    return 0;
}