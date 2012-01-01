#include "stdio.h"
#include "string.h"

bool flag[1001];
int n;

int main()
{
    int i;
    int m;
    int c;
    while(scanf("%d", &n) != -1)
    {
        memset(flag, 0, 1001);
        c = n;
        for(i = 0; i < n; i++)
        {
            scanf("%d", &m);
            if(flag[m] == 0) flag[m] = 1;
            else c--;
        }
        printf("%d\n", c);
        i = 0;
        bool f = 0;
        while(c)
        {
            if(flag[i])
            {
                if(f) printf(" ");
                printf("%d", i);
                f = 1;
                c--;
            }
            i++;
        }
        printf("\n");
    }

    return 0;
}