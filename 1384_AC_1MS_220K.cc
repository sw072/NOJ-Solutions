#include "iostream"
using namespace std;

int height[2000],e=0;

int GetMaxHeight(int s,int a)
{
    int maxHeight=-1;
    int i;
    for(i=0;i<a;i++)
    {
        if(height[s+i]>maxHeight)
            maxHeight=height[s+i];
    }
    return maxHeight;
}

int main()
{
    int n;
    int i,j;
    int h,w;
    int a;
    int minHeight=99999999;
    int temp;
    while(cin>>n)
    {
        e=0;
        for(i=0;i<n;i++)
        {
            cin>>w>>h;
            for(j=e;j<e+w;j++)
            {
                height[j]=h;
            }
            e=e+w;
        }
        cin>>a;
        for(i=0;i<e-a+1;i++)
        {
            temp=GetMaxHeight(i,a);
            if(temp<minHeight)
            {
                minHeight=temp;
            }
        }
        cout<<minHeight+a<<endl;
    }

    return 0;
}