#include "stdio.h"
#include "stdlib.h"

struct Item{
    int have;
    int need;
};

Item items[10001];
int n, s;

int comp(const void *a, const void *b)
{
    return ((Item *)a)->need - ((Item *)b)->need;
}

int main()
{
    int i;
    while(scanf("%d%d", &n, &s) != -1)
    {
        if(n == 0 && s == 0) break;
        for(i = 0; i < n; i++)
        {
            scanf("%d%d", &items[i].have, &items[i].need);
        }
        qsort(items, n, sizeof(Item), comp);
        for(i = 0; i < n; i++)
        {
            if(items[i].need <= s)
                s = s + items[i].have;
            else
            {
                printf("NO\n");
                break;
            }
        }
        if(i == n) printf("YES\n");
    }

    return 0;
}