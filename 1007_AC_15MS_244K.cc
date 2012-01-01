#include "stdio.h"

typedef unsigned long long ull;

int n;
ull record[30][30];
int root[30][30];

void previsit(int s, int e, bool first)
{
    if(s > e) return;
    if(!first) printf(" ");
    printf("%d", root[s][e]);
    previsit(s, root[s][e] - 1, false);
    previsit(root[s][e] + 1, e, false);
}

void dp()
{
    int i, j, k, root0;
    ull max = -1;
    ull r;
    for(i = 2; i <= n; i++)
    {
        for(j = i - 1; j >= 1; j--)
        {
            max = record[j][i - 1] + record[i][i];
            root0 = i;
            r = record[j][j] + record[j+ 1][i];
            if(r >= max)
            {
                max = r;
                root0 = j;
            }
            for(k = j + 1; k < i; k++)
            {
                r = record[j][k - 1] * record[k+1][i] + record[k][k];
                if(r >= max)
                {
                    max = r;
                    root0 = k;
                }
            }
            record[j][i] = max;
            root[j][i] = root0;
        }
    }
}

int main()
{
    int i;
    scanf("%d", &n);
    for(i = 1; i <= n; i++)
    {
        scanf("%d", &record[i][i]);
        root[i][i] = i;
    }
    dp();
    printf("%d\n", record[1][n]);
    previsit(1, n, true);
    printf("\n");

    return 0;
}