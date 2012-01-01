#include "stdio.h"
#include "string.h"

#define N 1001
#define max(a, b) (a > b ? a : b)

char str1[N];
char str2[N];

int m[N][N];

int LCS(char s1[], char s2[])
{
    memset(m, 0, N * N);
    int l1 = strlen(s1);
    int l2 = strlen(s2);
    int i, j;
    for(i = 1; i <= l1; i++)
        for(j = 1; j <= l2; j++)
        {
            if(s1[i - 1] != s2[j - 1])
            {
                m[i][j] = max(m[i - 1][j], m[i][j - 1]);
            }
            else if(s1[i - 1] == s2[j - 1])
            {
                m[i][j] = m[i - 1][j - 1] + 1;
            }
        }
    return m[l1][l2];
}

int main()
{
    while(scanf("%s %s", str1, str2) != -1)
    {
        printf("%d\n", LCS(str1, str2));
    }

    return 0;
}