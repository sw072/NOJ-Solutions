#include "stdio.h"

int GCD(int a, int b)
{
    int t, r;
    if(a == b) return b;
    if(a < b)
    {
        t = a;
        a = b;
        b = t;
    }
    while(1)
    {
        r = a % b;
        if(r == 0) break;
        a = b;
        b = r;
    }

    return b;
}

int main()
{
    int a, b, c, d;
    int w;
    int m, n, g;
    scanf("%d", &w);
    int i;
    for(i = 0; i < w; i++)
    {
        scanf("%d %d %d %d", &a, &b, &c, &d);
        m = a * d + b * c;
        n = b * d;
        g = GCD(m, n);
        printf("%d %d\n", m / g, n / g);
    }
    return 0;
}