#include "stdio.h"
#include "iostream"
using namespace std;

int n,m,s,e;
bool map[101][101],flag[101];
int q[101],h,t;

void BFS()
{
    int i;
    while(h<t)
    {
        for(i=0;i<n;i++)
        {
            if(map[q[h]][i]==1 && i==e)
            {
                printf("yes\n");
                return;
            }
            if(map[q[h]][i]==1 && flag[i]==0)
            {
                q[t]=i;
                flag[i]=1;
                t++;
            }
        }
        h++;
    }
    printf("no\n");
}

int main()
{
    int temp,i,j;
    while(scanf("%d",&n)!=-1)
    {
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
            {
                scanf("%d",&temp);
                if(temp==1)
                    map[i][j]=1;
                else map[i][j]=0;
            }
            scanf("%d",&m);
            for(i=0;i<m;i++)
            {
                scanf("%d%d",&s,&e);
                s--;e--;
                memset(flag,0,sizeof(flag));
                q[0]=s;
                h=0;t=1;
                flag[0]=1;
                BFS();
            }
    }
    return 0;
}