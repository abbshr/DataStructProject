#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <time.h>

#define M 30
#define N 4000000

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

    /* KMP */
    t1 = clock();
    KMP(p, str, n, m);
    t2 = clock();
    printf("KMP匹配时间（ms）：%lf\n", (double)(t2 - t1));

    return 0;
}