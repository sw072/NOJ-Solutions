#include "stdio.h"

int n,k;
char str[11];
int pos[7];
long long max;

void dfs(int level, long long res)
{
    int i, num;
    num = 0;
    if(level == k + 1)
    {
        for(i = pos[level - 1]; i < n; i++)
            num = num * 10 + str[i] - '0';
        res *= num;
        if(res > max)
            max = res;
        return;
    }
    for(i = pos[level - 1] + 1; i < n - (k - level); i++)
    {
        pos[level] = i;
        num = num * 10 + str[i - 1] - '0';
        dfs(level + 1, res * num);
    }
}

int main()
{
    scanf("%d%d", &n, &k);
    scanf("%s", str);
    pos[0] = 0;
    pos[k + 1] = n;
    dfs(1, 1);
    printf("%lld\n", max);

    return 0;
}