#include "iostream"
using namespace std;

int main()
{
    int n,k;
    int o[3][51];
    bool flag[51];
    int i,j;
    int winIndex,winFlag=0;
    while(cin>>n)
    {
        winFlag=0;
        for(i=0;i<3;i++)
            for(j=0;j<n;j++)
                cin>>o[i][j];
            cin>>k;
            for(i=0;i<n;i++)
                flag[i]=false;
            //cb,wb,pu
            while(!winFlag)
            {
                for(i=0;i<3;i++)
                {
                    if(winFlag) break;
                    for(j=0;j<n;j++)
                    {
                        if(flag[o[i][j]]==false)
                        {
                            flag[o[i][j]]=true;
                            if(o[i][j]==k)
                            {
                                winFlag=1;
                                winIndex=i;
                            }
                            break;
                        }
                    }
                }
            }
            if(winIndex==0) cout<<"cb"<<endl;
            if(winIndex==1) cout<<"wb"<<endl;
            if(winIndex==2) cout<<"pu"<<endl;
    }
    return 0;
}