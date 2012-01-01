#include "stdio.h"

int main()
{
    int k;
    int a1, a2, a3;
    int i;
    int flag;
    while(scanf("%d", &k) != -1)
    {
        flag = 0;
        for(i = 10000; i <= 30000; i++)
        {
            a1 = i / 100;
            if(a1 % k != 0) continue;
            a2 = (i % 10000) / 10;
            if(a2 % k != 0) continue;
            a3 = (i % 1000);
            if(a3 % k != 0) continue;
            printf("%d\n", i);
            flag = 1;
        }
        if(!flag) printf("No\n");
    }
    return 0;
}