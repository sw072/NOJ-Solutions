#include "iostream"
using namespace std;
#include "math.h"

int o[51][51][51];
int L,W,H;
int M;

int c=0;
bool visited[51][51][51];

void DFS(int i,int j,int k)
{
    visited[i][j][k]=true;
    if(k-1>=0 && abs(o[i][j][k]-o[i][j][k-1])<=M && visited[i][j][k-1]==false)
        DFS(i,j,k-1);
    if(k+1<H && abs(o[i][j][k]-o[i][j][k+1])<=M && visited[i][j][k+1]==false)
        DFS(i,j,k+1);
    if(j-1>=0 && abs(o[i][j][k]-o[i][j-1][k])<=M && visited[i][j-1][k]==false)
        DFS(i,j-1,k);
    if(j+1<W && abs(o[i][j][k]-o[i][j+1][k])<=M && visited[i][j+1][k]==false)
        DFS(i,j+1,k);
    if(i-1>=0 && abs(o[i][j][k]-o[i-1][j][k])<=M && visited[i-1][j][k]==false)
        DFS(i-1,j,k);
    if(i+1<L && abs(o[i][j][k]-o[i+1][j][k])<=M && visited[i+1][j][k]==false)
        DFS(i+1,j,k);
}

int main()
{
    int i,j,k;

    while(cin>>L>>W>>H)
    {
        cin>>M;
        for(i=0;i<L;i++)
            for(j=0;j<W;j++)
                for(k=0;k<H;k++)
                {
                    cin>>o[i][j][k];
                    visited[i][j][k]=false;
                }
        c=0;
        for(i=0;i<L;i++)
            for(j=0;j<W;j++)
                for(k=0;k<H;k++)
                {
                    if(visited[i][j][k]==false)
                    {
                        DFS(i,j,k);
                        c++;
                    }
                }
        cout<<c<<endl;
    }

    return 0;
}