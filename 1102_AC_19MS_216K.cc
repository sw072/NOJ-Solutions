#include "stdio.h"

int gcd(int a, int b)
{// a > b
    int t;
    if(a < b)
    {
        t = a;
        a = b;
        b = t;
    }
    while(1)
    {
        if(!(a % b)) return b;
        t = a % b;
        a = b;
        b = t;
    }
}

int main()
{
    int n;
    int ngcd;
    int a, i;
    scanf("%d", &n);
    scanf("%d", &ngcd);
    for(i = 1; i < n; i++)
    {
        scanf("%d", &a);
        ngcd = gcd(ngcd, a);
        if(ngcd == 1)
            break;
    }
    printf("%d\n", ngcd);

    return 0;
}