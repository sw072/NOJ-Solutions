#include "stdio.h"
#include "string.h"

int n, k;
int flag[10];


int n_factor(int n)
{
    if(n == 1 || n == 0) return 1;
    int i = 0;
    int res = 1;
    for(i = n; i > 1; i--)
        res = res * i;
    return res;
}

int get_the_ith(int ith)
{
    int m = 0, i = 0;
    while(m != ith)
    {
        i++;        
        if(flag[i] == 0) m++;

    }
    return i;
}

void print_result(int n, int k)
{
    int i = 0, j, c, t;
    for(i = 0; i < n; i++)
    {
        c = n_factor(n - i - 1);
        if(k % c != 0 || k == 0) t = (k / c) + 1;
        else t = k / c;
        j = get_the_ith(t);
        printf("%d", j);
        flag[j] = 1;
        k = k - (t - 1) * c;
    }
    printf("\n");
}

int main()
{
    while(scanf("%d%d", &n, &k) != -1)
    {
        k = k % n_factor(n) + 1;
        memset(flag, 0 , 10 * sizeof(int));
        print_result(n, k);
    }

    return 0;
}
