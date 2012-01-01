#include "stdio.h"

int main()
{
    int a, b, c;
    while(scanf("%d%d", &a, &c) != -1)
    {
        printf("%d\n",  (c << 1) - a);
    }

    return 0;
}