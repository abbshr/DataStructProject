
void preprocess(int* P, char* B, int m)
{
    *P = 0;
    int j = 0;
    int i;
    for (i = 0; i <= m; i++)
    {
        while (j > 0 && *(B + j + 1) != *(B + i))
            j = *(p + j);
        if (*(B + j + 1) == *(B + i))
            j++;
        *(P + i) = j;
    }
}

void KMP(int* P, char* B, char* A, int n, int m)
{
    int j = 0;
    int i;
    for (i = 0; i <= n; i++)
    {
        while (j > 0 && *(B + j + 1) != *(A + i))
            j = *(P + j);
        if (*(B + j + 1) == *(A + i))
            j++;
        if (j == m) 
        {
            printf("%d ", i - m);
            j = *(P + j);
        }
    }
}