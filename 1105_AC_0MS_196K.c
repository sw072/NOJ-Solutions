#include "stdio.h"
#include "string.h"

int main()
{
    int n;
    int i, j;
    int len;
    char res[51];
    char str[51];
    char s[51];
    while(scanf("%d", &n) != -1)
    {
        scanf("%s", res);
        strcpy(s, res);
        len = strlen(res);
        for(i = 1; i < n; i++)
        {
            scanf("%s", str);
            for(j = 0; j < len; j++)
            {
                if(res[j] == '?') continue;
                s[j] = res[j] ^ str[j];
                if(s[j] != 0) res[j] = '?';
            }
        }
        printf("%s\n", res);
    }

    return 0;
}