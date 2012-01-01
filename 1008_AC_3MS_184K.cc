#include "stdio.h"

int n;
int h[202];

int Up(int b[],int k)
{
    if(k==0)
        return 0;
    int a[202],i,j,max,t;
    a[0]=1;
    for(i=1;i<k;i++)
    {
        max=-1;
        for(j=0;j<i;j++)
            if(b[i]>b[j])
            {
                t=a[j]+1;
                if(t>max)
                    max=t;
            }
        if(max==-1)
            a[i]=1;
        else a[i]=max;
    }
    max=-1;
    for(i=0;i<k;i++)
        if(a[i]>max)
            max=a[i];
    return max;
}

int Down(int b[],int k)
{
    if(k==0)
        return 0;
    int a[202],i,j,max,t;
    a[0]=1;
    for(i=1;i<k;i++)
    {
        max=-1;
        for(j=0;j<i;j++)
            if(b[i]<b[j])
            {
                t=a[j]+1;
                if(t>max)
                    max=t;
            }
        if(max==-1)
            a[i]=1;
        else a[i]=max;
    }
    max=-1;
    for(i=0;i<k;i++)
        if(a[i]>max)
            max=a[i];
    return max;
}


int main()
{
    int i,j,left,right,min=65535;
    while(scanf("%d",&n)!=-1)
    {
        for(i=0;i<n;i++)
            scanf("%d",&h[i]);
        min=65535;
        for(i=0;i<n;i++)
        {
            int a[202],c=0;
            for(j=0;j<i;j++)
            {
                if(h[j]<h[i])
                {
                    a[c]=h[j];
                    c++;
                }
            }
            left=Up(a,c);
            c=0;
            for(j=i+1;j<n;j++)
            {
                if(h[j]<h[i])
                {
                    a[c]=h[j];
                    c++;
                }
            }
            right=Down(a,c);
            int temp=n-(left+right+1);
            if(temp<min)
                min=temp;
        }
        printf("%d\n",min);
    }

    return 0;
}