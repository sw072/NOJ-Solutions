#include "stdio.h"

int num[9] = {0, 10, 10, 100, 100, 1000, 1000, 10000, 10000};
int cumsum[9] = {0, 10, 20, 120, 220, 1220, 2220, 12220, 22220};
int s[9] = {0, 9, 18, 108, 198, 1098, 1998, 10998, 19998};
int result[9];
int idx;

void dfs(int level, int width, int pos)
{
    if(width == 1 || width == 2)
    {
        idx = level;
        result[level] = pos - 1;
        return;
    }
    result[level] = pos / num[width - 2];
    if(!(pos % num[width - 2])) result[level]--;
    pos = pos - (result[level] * num[width - 2]);
    dfs(++level, width - 2, pos);
}

int main()
{
    int n;
    int i, j, k, pos;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &pos);
        j = 0;
        while(pos > s[++j]);
        if(j == 1)
        {
            printf("%d\n", pos);
            continue;
        }
        if(j == 2)
        {
            pos -= s[1];
            printf("%c%c\n", pos + '0', pos + '0');
            continue;
        }
        // j >= 3
        pos -= s[j - 1];
        result[1] = pos / num[j - 2];
        if(pos % num[j - 2]) result[1]++;
        pos -= (result[1] - 1) * num[j - 2];
        dfs(2, j - 2, pos);
        for(k = 1; k <= idx; k++)
            printf("%c", result[k] + '0');
        if(!(j % 2)) k = idx;
        else k = idx - 1;
        for(; k >= 1; k--)
            printf("%c", result[k] + '0');
        printf("\n");
    }

    return 0;
}