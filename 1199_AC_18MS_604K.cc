#include "stdio.h"

#define N 201

int step[N];
bool cover[N];
int n, a, b;
short int q[100000];
short int p[100000];
int head, tail;

int bfs()
{
    bool flag = false;
    int t;
    if(a == b) return 0;
    q[0] = a;
    p[0] = 0;
    head = 0;
    tail = 1;
    cover[q[head]] = true;
    while(head < tail)
    {
        t = q[head] - step[q[head]];
        if(t > 0 && !cover[t])
        {
            q[tail] = t;
            p[tail] = p[head] + 1;
            cover[t] = true;
            if(q[tail] == b)
            {
                flag = true;
                break;
            }
            tail++;
        }
        t = q[head] + step[q[head]];
        if(t <= N && !cover[t])
        {
            q[tail] = t;
            p[tail] = p[head] + 1;
            cover[t] = true;
            if(q[tail] == b)
            {
                flag = true;
                break;
            }
            tail++;
        }
        head++;
    }
    if(flag) return p[tail];
    return -1;
}

int main()
{
    int i;
    scanf("%d%d%d", &n, &a, &b);
    for(i = 1; i <= n; i++)
        scanf("%d", &step[i]);
    printf("%d\n", bfs());

    return 0;
}