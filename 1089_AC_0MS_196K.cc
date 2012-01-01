#include "stdio.h"
#include "math.h"

int main()
{
    int n;
    int i, n_sqrt;
    int sum;
    while(scanf("%d", &n) != -1)
    {
        sum = 0;
        n_sqrt = (int)sqrt((double)n);
        for(i = 1; i <= n_sqrt; i++)
        {
            if(n % i == 0)
                sum = sum + i + n / i;
        }
        if(n_sqrt * n_sqrt == n) sum -= n_sqrt;
        printf("%d\n", sum);
    }
    return 0;
}