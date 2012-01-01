#include "stdio.h"

int count,num;
int max=-1,sec=-1;

int main()
{
    int i,m;
    while(scanf("%d %d",&count,&num))
    {
        max=-1,sec=-1;
        if(count==0 && num==0)
            break;
        for(i=0;i<count;i++)
        {
            scanf("%d",&m);
            if(m>max && m<num)
            {
                sec=max;
                max=m;
            }
            else if(m<=max && m>sec)
                sec=m;
        }
        printf("%d\n",sec);
    }
    return 0;
}