#include "stdio.h"

int main()
{
    int a,b,c;
    while(scanf("%d%d",&a,&c)!=-1)
    {
        printf("%d\n",2*c-a);
    }
    return 0;
}