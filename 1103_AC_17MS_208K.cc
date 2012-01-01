#include "stdio.h"
#include "math.h"

int time(int n)
{
    if(n == 1) return 1;
    double x = (-1 + sqrt(8 * (double)n + 1)) / 2;
    int t = (int)x;
    if(t * (t + 1) / 2 == n)
        return t;
    x = (-3 + sqrt(8 * (double)n + 1)) / 2;
    t = ceil(x);
    int left = n - (t * (t + 1)) / 2;
    return t + time(left);
}

int main()
{
    int n;
    while(scanf("%d", &n) != -1)
    {
        printf("%d\n", time(n));
    }

    return 0;
}