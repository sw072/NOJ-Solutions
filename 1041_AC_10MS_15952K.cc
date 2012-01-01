#include "iostream"
using namespace std;

bool f[100002];
int q[2000000];
int pace[2000000];
int h,t;
int F,C;

void BFS()
{
    while(h<t)
    {
        if(q[h]>0)
            if(f[q[h]-1]==0)
            {
                q[t]=q[h]-1;
                f[q[t]]=1;
                pace[t]=pace[h]+1;
                if(q[t]==C)
                {
                    cout<<pace[t]<<endl;
                    return;
                }
                t++;
            }
        if(q[h]<100000)
            if(f[q[h]+1]==0)
            {
                q[t]=q[h]+1;
                f[q[t]]=1;
                pace[t]=pace[h]+1;
                if(q[t]==C)
                {
                    cout<<pace[t]<<endl;
                    return;
                }
                t++;
            }
        if(q[h]*2<=100000)
            if(f[q[h]*2]==0)
            {
                q[t]=q[h]*2;
                f[q[t]]=1;
                pace[t]=pace[h]+1;
                if(q[t]==C)
                {
                    cout<<pace[t]<<endl;
                    return;
                }
                t++;
            }
        h++;
    }
}

int main()
{
    while(cin>>F>>C)
    {
        if(F==C)
        {
            cout<<0<<endl;
            continue;
        }
        memset(pace,0,sizeof(pace));
        memset(f,0,sizeof(f));
        h=0;
        t=1;
        q[0]=F;
        f[F]=1;
        BFS();
    }

    return 0;
}