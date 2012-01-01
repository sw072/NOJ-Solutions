#include "stdio.h"

int main()
{
    int n, m, s, i;
    while(scanf("%d", &n) != -1)
    {
        s = 0;
        n = 1 << n;
        for(i = 1; i < n; i++)
        {
            scanf("%d", &m);
            m--;
            s = s ^ m;
        }
        printf("%d\n", s + 1);
    }
    return 0;
}