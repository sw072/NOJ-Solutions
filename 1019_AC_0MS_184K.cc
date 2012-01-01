#include "stdio.h"

int n,a[101];

int Dp()
{
    int b[101],i;
    b[0]=a[0];
    for(i=1;i<n;i++)
    {
        if(b[i-1]>0)
            b[i]=b[i-1]+a[i];
        else b[i]=a[i];
    }
    int max=-3000000;
    for(i=0;i<n;i++)
        if(b[i]>max)
            max=b[i];
    return max;
}

int main()
{
    int i;
    while(scanf("%d",&n)!=-1)
    {
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        int max=Dp();
        printf("%d\n",max);
    }

    return 0;
}