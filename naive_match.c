
void Naive_Match(char* P, char* T, int n, int m)
{
    int i, j;
    for (i = 0; i < n - m + 1; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (*(P + j) != *(T + i + j))
                continue;
        }
        if (j == m)
            printf("%d ", i);
    }
}