#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <time.h>

#define M 30
#define N 4000000

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
    clock_t t1, t2;

    char str[N], p[M];

    /* read from file s*/
    /* string length: 400W */
    FILE* fp = NULL;
    fp = fopen("test", "r");
    while (fscanf(fp, "%s", str) != -1);
    int n = strlen(str);

    /* input pattern str */ 
    printf("输入模式串：\n");
    scanf("%s", p);
    int m = strlen(p);

    /* Naive Match */
    t1 = clock();
    Naive_Match(p, str, n, m);
    t2 = clock();
    printf("Naive匹配时间（ms）：%lf\n", (double)(t2 - t1));

    return 0;
}