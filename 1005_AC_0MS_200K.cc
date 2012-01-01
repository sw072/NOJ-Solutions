
#include "iostream"
#include "stdio.h"
using namespace std;

int h[32];
int n;

int DownOrder(int p[],int path[],int &pos)
{
    int i,j,a[32],t,max=-1;
    a[1]=1;
    for(i=2;i<=p[0];i++)
    {
        if(p[i]!=-1)
        {
            max=-1;
            for(j=0;j<i;j++)
                if(p[i]<p[j] && p[j]!=-1)
                {
                    t=a[j]+1;
                    if(t>max)
                    {
                        max=t;
                        path[i]=j;        //i??????????????j
                    }
                }
                a[i]=max;
                if(a[i]==-1)
                    a[i]=1;
        }
    }
    max=-1;
    for(i=1;i<=p[0];i++)
        if(a[i]>max)
        {
            pos=i;
            max=a[i];
        }
        return a[pos];
}


void Flag(int s[],int path[],int i)
{
    if(i==-1)
        return;
    s[i]=-1;
    Flag(s,path,path[i]);
}


int main()
{
    int path[32],pos,c=0,i,j;
    n=0;
    while(scanf("%d",&h[n+1])!=-1)
        n++;
    h[0]=n;
    memset(path,-1,sizeof(path));
    int t=DownOrder(h,path,pos);
    printf("%d\n",t);
    Flag(h,path,pos);
    int a[32];
    j=1;
    for(i=1;i<=h[0];i++)
    {
        if(h[i]!=-1)
        {
            a[j]=h[i];
            j++;
        }
    }
    a[0]=j-1;
    for(i=1;i<=a[0];i++)
        h[i]=a[i];
    h[0]=a[0];
    c=1;
    while(h[0])
    {
        memset(path,-1,sizeof(path));
        DownOrder(h,path,pos);
        Flag(h,path,pos);
        j=1;
        for(i=1;i<=h[0];i++)
        {
            if(h[i]!=-1)
            {
                a[j]=h[i];
                j++;
            }
        }
        a[0]=j-1;
        for(i=1;i<=a[0];i++)
            h[i]=a[i];
        h[0]=a[0];
        c++;
    }
    printf("%d\n",c);
    return 0;
}