#include "stdio.h"

int main()
{
    char c;
    while(scanf("%c", &c) != -1)
    {
        if(c == '<')
        {printf("&lt;");}
        else if(c == '>')
        {printf("&gt;");}
        else if(c == ' ')
        {printf("&nbsp;");}
        else if(c == '\t')
        {printf("&#9;");}
        else
        {printf("%c", c);}
    }

    return 0;
}