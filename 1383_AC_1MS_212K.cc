#include "iostream"
using namespace std;
#include "string.h"

bool IsDouble(char chain[],int s,int e)
{
    int i,j;
    j=e/2+1;
    for(i=e/2;i>=0;i--,j++)
    {
        if(chain[i]!=chain[j])
            return false;
    }
    return true;
}

int main()
{
    char chain[50];
    int s,e;
    cin>>chain;
    s=0,e=strlen(chain)-1;
    while((e+1)%2==0)
    {
        if(IsDouble(chain,s,e))
        {
            e=e/2;
        }
        else break;
    }
    cout<<e+1<<endl;

    return 0;
}