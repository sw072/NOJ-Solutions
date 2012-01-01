#include "stdio.h"
#include "math.h"

int vw,vp;

int main()
{
    int i,n,x,y,c;
    while(scanf("%d%d",&vw,&vp)!=-1)
    {
        scanf("%d",&n);
        c=0;
        if(vw==0)
        {
            for(i=0;i<n;i++)
            {
                scanf("%d%d",&x,&y);
                if(x==0)
                {
                    c++;
                }
            }
        }
        else
        {
            for(i=0;i<n;i++)
            {
                scanf("%d%d",&x,&y);
                double dif=(double)((double)y/x-(double)vp/vw)>0?((double)y/x-(double)vp/vw):-((double)y/x-(double)vp/vw);
                if(dif<=0.0000001)
                {
                    c++;
                }
            }
        }
        printf("%d\n",c);
    }

    return 0;
}