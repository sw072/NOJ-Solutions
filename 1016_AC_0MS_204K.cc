#include "stdio.h"
#include "iostream"
using namespace std;

int num;
bool map[51][51],flag[51];

bool IsCon()
{
    int q[52],h=0,t=1,i;
    q[0]=0;
    flag[0]=1;
    while(h<t)
    {
        for(i=0;i<num;i++)
            if(i!=q[h])
            {
                if(map[q[h]][i]==1 && flag[i]==0)
                {
                    q[t]=i;
                    flag[i]=1;
                    t++;
                }
            }
        h++;
    }
    for(i=0;i<num;i++)
        if(flag[i]==0)
            return 0;
    return 1;
}

bool Judge()
{
    int out,i,j,c=0;
    for(i=0;i<num;i++)
    {
        out=0;
        for(j=0;j<num;j++)
            if(map[i][j])
                out++;
        if(out%2==1)
            c++;
    }
    if(c==0 || c==2)
        return 1;
    return 0;
}


int main()
{
    int i,j,k;
    while(scanf("%d",&num)!=-1)
    {
        memset(map,0,sizeof(map));
        for(i=0;i<num;i++)
            for(j=0;j<num;j++)
            {
                scanf("%d",&k);
                if(k==1)  map[i][j]=1;
                else map[i][j]=0;
            }
            memset(flag,0,sizeof(flag));
            if(IsCon() && Judge())
                printf("yes\n");
            else printf("no\n");
    }
    return 0;
}