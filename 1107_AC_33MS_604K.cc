#include "stdio.h"
#include "stdlib.h"

#define N 100000

int s[N];
int n, len;

//return position of the number <= num
int find(int num)
{
    int low, high, mid;
    low = 0;
    high = n - 1;
    while(low <= high)
    {
        mid = (low + high) / 2;
        if(s[mid] < num) low = mid + 1;
        else if(s[mid] > num) high = mid - 1;
        else break;
    }
    return mid;
}

int comp(const void *a, const void *b)
{
    int x = *(int *)a;
    int y = *(int *)b;
    if(x == y) return 0;
    if(x > y) return 1;
    else return -1;
}

int main()
{
    int i, pos;
    unsigned long long c;
    while(scanf("%d %d", &n, &len) != -1)
    {
        for(i = 0; i < n; i++)
            scanf("%d", &s[i]);
        qsort(s, n, sizeof(int), comp);
        //printf("%d\n", find(3));
        c = 0;
        /*
        for(i = 0; i < pos; i++)
        {
            pos = find(len - s[i]);
            c += (unsigned long long)(pos - i);
        }
        */
        if(s[0] + s[1] > len)
        {
            printf("0.00\n");
            continue;
        }
        i = 0;
        pos = n - 1;
        while(i < pos)
        {
            if(s[i] + s[pos] <= len)
            {
                c += (pos - i);
                i++;
            }
            else
            {
                pos--;
            }
        }
        printf("%.2f\n", 2.0 * c / ((float)n * (n - 1)));
    }
    return 0;
}