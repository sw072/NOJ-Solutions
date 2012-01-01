#include "iostream"
#include "string.h"
using namespace std;

int r[120];

//a,b????????max??a,b??????????????result????????n????????????
void BigNumAdd(int *a,int *b,int max,int *result,int &n)
{
    int i,carry=0;
    memset(result,0,sizeof(result));
    for(i=0;i<max;i++)
        result[i]=a[i]+b[i];
    for(i=0;i<max;i++)
    {
        if((result[i]+carry)>9)
        {
            result[i]=(result[i]+carry)%10;
            carry=1;
        }
        else
        {
            result[i]=result[i]+carry;
            carry=0;
        }
    }
    if(carry==1)
    {
        result[max]=1;
        n=max+1;
        return;
    }
    n=max;
    return;
}

void Change(char *t,int *n)
{
    memset(n,0,sizeof(n));
    int len=strlen(t);
    int i;
    for(i=0;i<len;i++)
    {
        n[i]=t[len-i-1]-'0';
    }
}

void PrintResult(int *k,int n)
{
    int i;
    for(i=n-1;i>=0;i--)
    {
        cout<<k[i];
    }
    cout<<endl;
}

void MoveZero(char *p)
{
    int i,len=strlen(p);
    for(i=0;i<len;i++)
    {
        if(p[i]!='0')
            break;
    }
    strcpy(p,p+i);
}

void Copy(int *a,int *b,int n)
{
    int i;
    for(i=0;i<n;i++)
        a[i]=b[i];
}

int main()
{
    char t1[120];
    int a[120],max,key[120],nr;
    while(cin.getline(t1,120))
    {
        memset(key,0,sizeof(key));
        MoveZero(t1);
        memset(a,0,sizeof(a));
        Change(t1,a);
        max=strlen(t1);
        BigNumAdd(a,key,max,key,nr);
        
        cin.getline(t1,120);
        {
            if(t1[0]=='0' && t1[1]==0)
                break;
            MoveZero(t1);
            memset(a,0,sizeof(a));
            Change(t1,a);
            max=strlen(t1)>nr?strlen(t1):nr;
            BigNumAdd(a,key,max,r,nr);        //r=a+key
            Copy(key,r,nr);                    //key=r;
        }
        PrintResult(r,nr);        
    }
    return 0;
}