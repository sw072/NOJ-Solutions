#include "stdio.h"
#include "iostream"
using namespace std;

int n;
short int map[201][201];

int Dp(short int a[])
{
    short int b[201];
    b[0]=a[0];
    int i;
    for(i=1;i<n;i++)
    {
        if(b[i-1]>=0)
            b[i]=b[i-1]+a[i];
        if(b[i-1]<0)
            b[i]=a[i];

    }
    short int max=-20000;
    for(i=0;i<n;i++)
        if(b[i]>max)
            max=b[i];
    return max;
}

int Cal()
{
    short int a[201];
    int i,j,k;
    short int max=-20000,temp;
    for(i=0;i<n;i++)
    {
        memset(a,0,sizeof(a));
        for(j=1;j<=n-i;j++)
        {
            for(k=0;k<n;k++)
                a[k]+=map[i+j-1][k];
            temp=Dp(a);
            if(temp>max)
                max=temp;
        }
    }
    return max;
}

int main()
{
    int i,j;
    while(scanf("%d",&n)!=-1)
    {
        memset(map,0,sizeof(map));
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                scanf("%d",&map[i][j]);
        short int max=Cal();
        printf("%d\n",max);
    }
    return 0;
}