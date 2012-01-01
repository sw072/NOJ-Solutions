#include "stdio.h"
#include "stdlib.h"

int main()
{
    int h, m, s;
    int sec;
    int a, b, c;
    while(scanf("%d:%d:%d", &h, &m, &s) != -1)
    {
        if(h >= 12) h -= 12;
        sec = h * 3600 + m * 60 + s;
        int arcm = (360 * sec) % (360 * 3600);
        int arch = (30 * sec) % (360 * 3600);
        int res = abs(arcm - arch);
        if(res >= 180 * 3600)
            res = 360 * 3600 - res;
        a = res / 3600;
        b = (res - a * 3600) / 60; 
        c = res - a * 3600 - b * 60;
        printf("%d^%d'%d\"\n", a, b, c);
    }

    return 0;
}