#include "iostream"
using namespace std;

int main()
{
    int f[1001],g[1001];
    int nf,ng;
    int i,j;
    int result=0;
    while(cin>>nf>>ng)
    {
        result=0;
        for(i=0;i<nf;i++)
            cin>>f[i];
        for(i=0;i<ng;i++)
            cin>>g[i];
        for(i=0;i<nf;i++)
            for(j=0;j<ng;j++)
            {
                if(f[i]>g[j])
                    result++;
            }
        cout<<result<<endl;
    }
    return 0;
}