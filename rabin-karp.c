
void Rabin_Karp(char* T, char* P, int n, int m, int d, int q)
{
    int h = pow(d, m - 1) % q;
    int p = 0;
    int t = 0;
    int i, s, j;
	
    for (i = 0; i < m; i++)
    {
        p = (d * p + *(P + i)) % q;
        t = (d * t + *(T + i)) % q; 
    }

    for (s = 0; s < n - m; s++)
    {
        if (p == t)
        {
            for (j = 0; j < m; j++)
            {
                 if (*(T + s + j) == *(P + j))
                    break;       
            }
            if (j == m)
                printf("%d ", s);
        }

        if (s < n - m)
            t = (d * (t - *(T + s + 1) * h) + *(T + s + m + 1));
    }
}