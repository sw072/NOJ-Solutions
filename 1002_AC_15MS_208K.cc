#include "stdio.h"

int main()
{
    int m,n;
    int x,y;
    while(scanf("%d%d",&m,&n))
    {
        if(m == 0 && n == 0)
            break;
        if(n % 2 != 0)
        {
            printf("Error\n");
            continue;
        }
        y = n / 2 - m;
        x = m - y;
        if(x < 0 || y < 0)
        {
            printf("Error\n");
            continue;
        }
        printf("%d %d\n", x, y);
    }

    return 0;
}