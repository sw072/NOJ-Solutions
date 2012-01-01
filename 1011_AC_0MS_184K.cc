#include "stdio.h"
#include "string.h"

int n;
char str[1002];

int main()
{
    char name[1002];
    int i;
    while(scanf("%d",&n)!=-1)
    {
        scanf("%s",str);
        for(i=0;i<n;i++)
        {
            scanf("%s",name);
            if(strstr(str,name)!=0)
                printf("yes\n");
            else printf("no\n");
        }
    }

    return 0;
}