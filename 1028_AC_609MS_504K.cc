#include "iostream"
using namespace std;

#define N 80000

int Partition(int *a,int s,int e)
{
    int i=s,j=e+1;
    int k=a[s];
    int t;
    while(1)
    {
        while(i<=e && a[++i]<k);
        while(a[--j]>k);
        if(i>=j)
            break;
        t=a[i];
        a[i]=a[j];
        a[j]=t;
    }
    if(i<=e)
    {
        a[s]=a[j];
        a[j]=k;
    }
    else
    {
        a[s]=a[e];
        a[e]=k;
    }
    return j;
}

void Qsort(int *a,int s,int e)
{
    if(s>=e)
        return;
    int pos=Partition(a,s,e);
    Qsort(a,s,pos-1);
    Qsort(a,pos+1,e);
}



int main()
{
    int n,i;
    int a[N+1];
    while(cin>>n)
    {
        for(i=0;i<n;i++)
            cin>>a[i];
        Qsort(a,0,n-1);
    
        for(i=0;i<n;i++)
            cout<<a[i]<<endl;
    }
    
    return 0;
}