#include "stdio.h"
#include "iostream"
using namespace std;

int n,k;
bool map[52][52];
bool flag[52];
int q[10000],h,t;

bool BFS()
{
    int i;
    while(h<t)
    {
        for(i=0;i<n;i++)
            if(i!=q[h])
            {
                if(map[q[h]][i]==1 && flag[i]==0)
                {
                    if(i==k-1)
                        return 1;
                    q[t]=i;
                    flag[i]=1;
                    t++;
                }
            }
                h++;
        }
    return 0;
}

int main()
{
    int i,j,p;
    while(scanf("%d%d",&n,&k)!=-1)
    {
        memset(map,0,sizeof(map));
        memset(flag,0,sizeof(flag));
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
            {
                scanf("%d",&p);
                if(p==1)
                    map[i][j]=1;
                else map[i][j]=0;
            }
        q[0]=0;
        flag[0]=1;
        h=0,t=1;
        if(BFS())
            printf("Clever MM!\n");
        else printf("Naughty GG!\n");
    }
    return 0;
}