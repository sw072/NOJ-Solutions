#include "stdio.h"

void trans(int n, int dr)
{
    if(!n)
    {
        return;
    }
    trans(n / dr, dr);
    char b = n % dr;
    if(b >= 10) b = b -10 + 'A';
    else b = b + '0';
    printf("%c", b);
}

int main()
{
    int sr, dr;
    char num[32];
    int n_10;
    while(scanf("%d%s%d", &sr, num, &dr) != -1)
    {
        n_10 = 0;
        int i = 0;
        while(num[i])
        {
            if(num[i] >= 'A') num[i] = num[i] - 'A' + 10;
            else num[i] = num[i] - '0';
            n_10 = n_10 * sr + num[i];
            i++;
        }
        trans(n_10, dr);
        printf("\n");
    }

    return 0;
}