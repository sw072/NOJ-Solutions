#include<iostream>
using namespace std;
struct node{
    int t,h,f;
};
int D,N;
int temp(const void*n1,const void*n2)
{
    node x=*(node*)n1,y=*(node*)n2;
    return x.t-y.t;
}
int main()
{
    int i,j;
l:    while(cin>>D>>N)
    {
        node a[500];
        for (i=1;i<=N;i++)
            cin>>a[i].t>>a[i].f>>a[i].h;
        qsort(a+1,N,sizeof(node),temp);
        int f[200][200];
        for (i=0;i<=D;i++)
            for (j=0;j<=N;j++)
                f[i][j]=0xFFFFFFFE;
            f[0][0]=10;
            int maxs=0;
            for (i=1;i<=N;i++)
            {
                int kr=0xFFFFFFFE;
                for (j=maxs;j>=0;j--)
                    if (f[j][i-1]>=a[i].t)
                    {
                        int k=j+a[i].h;
                        if (k>=D)
                        {
                            cout<<a[i].t<<endl;
                            goto l;
                        }
                        else if (f[j][i-1]>f[k][i])
                        {
                            f[k][i]=f[j][i-1];
                            if (kr<k)
                                kr=k;
                        }
                        f[j][i]=f[j][i-1]+a[i].f;
                    }
                    if (f[0][i]<0)
                    {
                        cout<<f[0][i-1]<<endl;
                        goto l;
                    }
                    maxs=kr;
            }
            cout<<f[0][N]<<endl;
    }
    return 0;
}