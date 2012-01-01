#include "iostream"
#include "stdio.h"
using namespace std;

int n,map[8][8];

int Dp()
{
    int A[8][8];
    int i,j;
    A[n-1][0]=map[n-1][0];
    for(i=n-1;i>=0;i--)
        for(j=0;j<n;j++)
        {
            if(!(i==n-1 && j==0))
            {
                if(i==n-1)
                    A[i][j]=A[i][j-1]+map[i][j];
                else if(j==0)
                    A[i][j]=A[i+1][j]+map[i][j];
                else
                {
                    if(A[i][j-1]+map[i][j]>A[i+1][j]+map[i][j])
                        A[i][j]=A[i][j-1]+map[i][j];
                    else A[i][j]=A[i+1][j]+map[i][j];
                }
            }
        }
    return A[0][n-1];
}


int main()
{
    char ch[3];
    int i,j;
    while(scanf("%d",&n)!=-1)
    {
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
            {
                scanf("%s",ch);
                if(ch[0]>='2' && ch[0]<='9')
                    map[i][j]=ch[0]-'0';
                if(ch[0]=='A')
                    map[i][j]=1;
                if(ch[0]=='T')
                    map[i][j]=10;
                if(ch[0]=='J')
                    map[i][j]=11;
                if(ch[0]=='Q')
                    map[i][j]=12;
                if(ch[0]=='K')
                    map[i][j]=13;
            }
            int max=Dp();
            printf("%d\n",max);
    }

    return 0;
}