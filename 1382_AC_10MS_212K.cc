#include "iostream"
using namespace std;

int main()
{
    int n;
    int o[3];
    int i;
    int bestLen=-1,bestRadio=99999999,bestIndex=-1;
    while(cin>>n)
    {
        for(i=0;i<n;i++)
        {
            cin>>o[0]>>o[1]>>o[2];
            if(o[0]>bestLen)
            {
                bestLen=o[0];
                bestRadio=o[1];
                bestIndex=o[2];
            }
            else if(o[0]==bestLen)
            {
                if(o[1]<bestRadio)
                {
                    bestLen=o[0];
                    bestRadio=o[1];
                    bestIndex=o[2];
                }
                else if(o[1]==bestRadio)
                {
                    if(o[2]>bestIndex)
                    {
                        bestLen=o[0];
                        bestRadio=o[1];
                        bestIndex=o[2];
                    }
                }
            }
        }
        cout<<bestIndex<<endl;
    }
    return 0;
}