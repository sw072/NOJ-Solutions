#include "iostream"
using namespace std;

int main()
{
    int n;
    int vec[500];
    int i=0;
    int sum=0,avg=0,flag=1;
    while(cin>>n)
    {
        if(!n) break;
        sum=0;
        for(i=0;i<n;i++)
        {
            cin>>vec[i];
            sum+=vec[i];
        }
        avg=sum/(n/2);
        flag=1;
        for(i=0;i<n;i++)
        {
            if(vec[i]+vec[n-i-1]!=avg)
            {
                cout<<"no"<<endl;
                flag=0;
                break;
            }
        }
        if(flag)
            cout<<"yes"<<endl;

    }
    return 0;
}