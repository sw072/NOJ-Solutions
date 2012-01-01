#include "iostream"
using namespace std;

char sc[20][3];
int m=0,n=1;
int scsum[20];

int main()
{
        int i=0;
        while(cin>>sc[n])
        {
            n++;
        }
        n--;
        m=n;
        if(m>10) m=10;
        int flag=0;
        for(i=1;i<=m;i++)
        {
            flag=0;
            int temp=0;
            if(sc[i][0]=='/')
            {
                temp=10;
                if(i+1<=n)
                {
                    if(sc[i+1][0]=='/')
                    {
                        temp+=10;
                        if(i+2<=n)
                        {
                            if(sc[i+2][0]=='/')
                            {
                                temp+=10;
                            }
                            else
                            {
                                temp+=sc[i+2][0]-'0';
                            }
                            flag=1;
                        }
                    }
                    else if(sc[i+1][1]=='/')
                    {
                        temp+=10;
                        flag=1;
                    }
                    else if(sc[i+1][1]>='0' && sc[i+1][1]<='9')
                    {
                        temp=temp+sc[i+1][0]-'0'+sc[i+1][1]-'0';
                        flag=1;
                    }
                }
            }
            else if(sc[i][1]=='/')
            {
                temp=10;
                if(i+1<=n)
                {
                    if(sc[i+1][0]=='/')
                        temp+=10;
                    else temp+=sc[i+1][0]-'0';
                    flag=1;
                }
            }
            else if(sc[i][1]!=0 && sc[i][1]!='/')
            {
                temp=sc[i][0]-'0'+sc[i][1]-'0';
                flag=1;
            }
            if(flag==1)
            {
                if(i!=1)
                    cout<<" ";
                cout<<temp;
                scsum[i]=scsum[i-1]+temp;
            }
            else
            {
                i--;
                break;
            }
        }
        cout<<endl;
        int j=0;
        if(i>m) i=m;
        for(j=1;j<=i;j++)
        {
            if(j!=1) cout<<" ";
            cout<<scsum[j];
        }
        cout<<endl;
    return 0;
}
