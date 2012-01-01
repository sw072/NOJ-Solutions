#include "stdio.h"

int appleh[10];
int h;
int c;

int main()
{
    int i;
    for(i = 0; i < 10; i++)
        scanf("%d", &appleh[i]);
    scanf("%d",&h);
    h += 30;
    c = 0;
    for(i = 0; i < 10; i++)
        if(appleh[i] <= h) c++;
    printf("%d\n", c);

    return 0;
}