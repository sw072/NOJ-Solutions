#include <stdio.h>
#include <algorithm>
using namespace std;

#define N 50001
short int arr[N];
int n;

int comp(const void *pa, const void *pb)
{
    const short int *_pa = (const short int *)pa;
    const short int *_pb = (const short int *)pb;
    return (*_pa - *_pb);
}

int main()
{
    int idx = 0;
    while(scanf("%d", &n) != -1)
    {
        for(idx = 0; idx < n; idx++)
            scanf("%d", &arr[idx]);
        qsort(arr, n, sizeof(short int), comp);
        int half = n / 2;
        int sum = 0;
        for(idx= 0; idx + 1 < n; idx += 2)
        {
            sum += (arr[idx] - arr[idx + 1]);
        }
        if(n % 2) sum += arr[n - 1];
        printf("%d\n", sum > 0 ? sum : -sum);
    }
    return 0;
}
