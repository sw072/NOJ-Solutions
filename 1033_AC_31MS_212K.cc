#include "iostream"
using namespace std;

int n;
bool map[101][101];
int q[101],h,t;
bool flag[101],fl;

void BFS(int s)
{
    int i;
    while(h<t)
    {
        for(i=0;i<n;i++)
        {
            if(map[q[h]][i]==1 && i==s)
            {
                fl=1;
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
            for(i=0;i<n;i++)
            {
                fl=0;
                memset(flag,0,sizeof(flag));
                q[0]=i;
                h=0;t=1;
                BFS(i);
                if(fl==1)
                {
                    printf("yes\n");
                    break;
                }
            }
            if(fl==0)
                printf("no\n");
    }

    return 0;
}