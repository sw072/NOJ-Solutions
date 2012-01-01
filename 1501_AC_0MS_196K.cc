#include "stdio.h"

void print_line(int h, int line)
{
    int whitespace = h / 2 - line + 1;
    int star = (line << 1) - 1;
    int i;
    for(i = 0; i < whitespace; i++)
        printf(" ");
    for(i = 0; i < star; i++)
        printf("*");
    printf("\n");
}

int main()
{
    int h;
    int i;
    while(scanf("%d", &h) != -1)
    {
        if(h == 0) break;
        int half = h / 2;
        for(i = 1; i <= half; i++)
            print_line(h, i);
        print_line(h, half+1);
        for(i = half; i >= 1; i--)
            print_line(h, i);
    }
    return 0;
}