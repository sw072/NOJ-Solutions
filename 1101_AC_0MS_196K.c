#include "stdio.h"

int array[21]={0,1,3,8,20,48,112,256,576,1280,2816,6144,13312,28672,61440,131072,278528,589824,1245184,2621440,5505024};

int high(int n)
{
    int i;
    int start = 1 << (n - 1);
    int end =  (1 << n) - 1;
    int sum = 0;
    for(i = start; i <= end; i++)
    {
        int t = i;
        while(t)
        {
            if(t % 2 == 1) sum++;
            t = t / 2;
        }
    }
    return sum;
}

int main()
{
    int n;
    int i;
    int d;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &d);
        printf("%d\n", array[d]);
    }

    return 0;
}