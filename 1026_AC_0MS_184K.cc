#include "stdio.h"

int n;
int a[101];

int main()
{
    int i;
    while(scanf("%d",&n)!=-1)
    {
        int min=100000,max=-10000;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            if(a[i]<min)
                min=a[i];
            if(a[i]>max)
                max=a[i];
        }
        printf("%d %d\n",max,min);
    }
}