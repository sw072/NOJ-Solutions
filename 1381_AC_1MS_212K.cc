#include "iostream"
using namespace std;

int main()
{
    int n;
    int i;
    int sum=0,k;
    while(cin>>n)
    {
        sum=0;
        k=0;
        for(i=1;i<=n;i++)
        {
            k+=i;
            sum+=k;
        }
        cout<<sum<<endl;
    }

    return 0;
}