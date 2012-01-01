#include "stdio.h"


int To10(int n)
{
    int a,sum=0;
    while(n>0)
    {
        a=n%10;
        sum+=a;
        n=n/10;
    }
    return sum;
}

int To12(int n)
{
    int a,sum=0;
    while(n>0)
    {
        a=n%12;
        sum+=a;
        n=n/12;
    }
    return sum;

}

int To16(int n)
{
    int a,sum=0;
    while(n>0)
    {
        a=n%16;
        sum+=a;
        n=n/16;
    }
    return sum;

}

int main()
{
    int i=2992;
    while(i<=9999)
    {
        if(To10(i)==To12(i) && To10(i)==To16(i))
            printf("%d\n",i);
        i++;
    }
    return 0;
}