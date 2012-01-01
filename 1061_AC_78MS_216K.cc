#include "stdio.h"
#include "math.h"

bool is_swike_set(int n)
{
    int i, bound;
    if(!n) return false;
    if(n == 1 || n == 2 || n == 5 || n == 8)
        return true;
    n++;
    bound = (int)sqrt((double)n);
    for(i = 2; i <= bound; i++)
    {
        if(!(n % i) && is_swike_set(i - 1) && is_swike_set(n / i - 1))
            return true;
    }
    return false;
}

int main()
{
    int n;
    while(1)
    {
        scanf("%d", &n);
        if(!n) break;
        printf("%s\n", is_swike_set(n) ? "yes" : "no");
    }

    return 0;
}