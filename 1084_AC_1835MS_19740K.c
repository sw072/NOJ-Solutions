#include "stdio.h"

int values[5000001];//5000001
int n;
int k;

int partition(int s, int e)
{
    int i,last_small;
    int pivot_value = values[s];
    int t = 0;
    last_small = s;
    for(i = s + 1; i <= e; i++)
    {
        if(values[i] <= pivot_value)
        {
            last_small++;
            t = values[last_small];
            values[last_small] = values[i];
            values[i] = t;
        }
    }
    values[s] = values[last_small];
    values[last_small] = pivot_value;
    return last_small;
}

int GetTheKthNum(int s, int e)
{
    int pivot = partition(s, e);
    if(pivot == k) return values[pivot];
    if(pivot > k) return GetTheKthNum(s, pivot-1);
    else if(pivot < k) return GetTheKthNum(pivot+1,e);
}

int main()
{
    int i = 0;
    while(    scanf("%d%d", &n, &k))
    {
        if(n == 0 && k == 0) break;
        k--;
        for(i = 0; i < n; i++)
            scanf("%d", &values[i]);
        printf("%d\n", GetTheKthNum(0, n-1));
    }
    return 0;
}
