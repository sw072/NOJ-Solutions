#include "stdio.h"
#include "string.h"

#define N 101
#define C 1001
#define max(a, b) ((a) > (b) ? (a) : (b))

struct thing
{
    int weight;
    int value;
};

int n, c;
thing t[N];
int w[N][C];

int DP()
{
    int i, j;
    for(i = 1; i <= n; i++)
        for(j = 0; j <= c; j++)
        {
            if(j >= t[i].weight)
                w[i][j] = max(w[i - 1][j], w[i - 1][j - t[i].weight] + t[i].value);
            else
                w[i][j] = w[i - 1][j];
        }
    return w[n][c];
}

int main()
{
    int i;
    while(scanf("%d%d", &n, &c) != -1)
    {
        memset(w, 0, N * C * 4);
        for(i = 1; i <= n; i++)
            scanf("%d%d", &t[i].value, &t[i].weight);
        printf("%d\n", DP());
    }

    return 0;
}