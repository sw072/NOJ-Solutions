#include "stdio.h"

int main()
{
    float c, w, b;
    while(scanf("%f%f%f", &c, &w, &b) != -1)
    {
        if(c >= w)
        {
            printf("-1\n");
            continue;
        }
        printf("%.2f\n", b / (w - c));
    }

    return 0;
}