#include "stdio.h"
#include "string.h"

#define L 15
#define D 5000
#define DICTLEN (D << 1)

#define hash(a, b) (((int)a * (int)b) % DICTLEN)

struct word
{
    char w[L + 1];
}dict[D];
int l, d, n;

bool pattern[L][27];


int match()
{
    int result = 0;
    int i, j;
    for(i = 0; i < d; i++)
    {
        for(j = 0; j < l; j++)
            if(!pattern[j][dict[i].w[j] - 'a']) break;
        if(j >= l) result++;
    }
    return result;
}


int main()
{
    int i, idx, idxl;
    char str[500];
    bool inbrackets;
    scanf("%d%d%d", &l, &d, &n);
    for(i = 0; i < d; i++)
    {
        scanf("%s", dict[i].w);
    }
    for(i = 0; i < n; i++)
    {
        idx = 0;
        idxl = 0;
        inbrackets = false;
        scanf("%s", &str);
        memset(pattern, 0, sizeof(pattern));
        while(str[idx])
        {
            if(str[idx] == '(')
            {
                inbrackets = true;
            }
            else if(str[idx] == ')')
            {
                idxl++;
                inbrackets = false;
            }
            else
            {
                pattern[idxl][str[idx] - 'a'] = true;
                if(!inbrackets)
                {
                    idxl++;
                }
            }
            idx++;
        }
        printf("Case #%d: %d\n", i + 1, match());
    }

    return 0;
}