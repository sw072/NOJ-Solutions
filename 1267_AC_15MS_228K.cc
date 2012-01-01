#include "stdio.h"

int main()
{
    int table[] = {1, 0, 0, 2, 10, 4, 40, 92, 352, 724, 2680, 14200, 73712};
    int n;
    while(scanf("%d", &n) != -1)
    {
        if(!n) break;
        printf("%d\n", table[n - 1]);
    }

    return 0;
}