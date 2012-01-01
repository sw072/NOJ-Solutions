#include "stdio.h"
#include "string.h"

#define N 51

bool map[N][N];
int n, k;
bool flag[N];
bool fined;

void dfs(int preidx)
{
    if(preidx == k - 1)
    {
        fined = true;
        return;
    }
    int i;
    if(!fined)
    {
        for(i = 0; i < n; i++)
        {
            if(map[preidx][i] && !flag[i])
            {
                flag[i] = true;
                dfs(i);
                flag[i] = false;
            }
        }
    }
}

int main()
{
    int i, j;
    while(scanf("%d%d", &n, &k) != -1)
    {
        for(i = 0; i < n; i++)
            for(j = 0; j < n; j++)
                scanf("%d", &map[i][j]);
        memset(flag, 0, N);
        fined = false;
        flag[0] = true;
        dfs(0);
        if(fined) printf("Clever MM!\n");
        else printf("Naughty GG!\n");
    }

    return 0;
}