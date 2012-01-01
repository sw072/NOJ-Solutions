#include "stdio.h"
#include "iostream"
using namespace std;

int n;
int map[501][501];

bool IsExi(int a[],int k)
{
    int b[501],i;
    if(a[0]==0)
        b[0]=1;
    else b[0]=0;
    if(b[0]>=k)
        return 1;
    for(i=1;i<n;i++)
    {
        if(a[i-1]==0 && a[i]==0)
            b[i]=b[i-1]+1;
        else if(a[i]!=0)
            b[i]=0;
        else if(a[i-1]!=0 && a[i]==0)
            b[i]=1;
        if(b[i]>=k)
            return 1;
    }
    return 0;
}

int Cal()
{
    int a[501];
    int i,j,k;
    int max=-20000,temp;
    for(i=0;i<n;i++)
    {
        memset(a,0,sizeof(a));
        for(j=1;j<=n-i;j++)
        {
            for(k=0;k<n;k++)
                a[k]+=map[i+j-1][k];
            if(IsExi(a,j))
                temp=j;
            else temp=-20000;
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
        int max=Cal();
        if(max<0)
            printf("0\n");
        else        printf("%d\n",max);
    }

    return 0;
}