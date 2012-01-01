#include "stdio.h"

#define N 101
#define MAX 2147483647

int n;
int g[N][N];

int mini_spanning_tree(int n, int g[N][N])
{
    bool s[N];
    int distance[N];
    int neigber[N];
    int source = 0;
    int i, j;
    int min_span = 0;
    for(i = 0; i < n; i++)
    {
        s[i] = false;
        distance[i] = g[source][i];
        neigber[i] = source;
    }
    s[source] = true;
    int min = MAX;
    int v;
    for(i = 0; i < n; i++)
    {
        min = MAX;
        for(j = 0; j < n; j++)
        {
            if(!s[j] && distance[j] < min)
            {
                min = distance[j];
                v = j;
            }    
        }
        if(min != MAX)
        {
            s[v] = true;
            min_span += min;
            for(j = 0; j < n; j++)
            {
                if(!s[j] && distance[j] > g[v][j])
                {
                    distance[j] = g[v][j];
                }
            }
        }
    }
    return min_span;
}

void init_g(int size)
{
    int i, j;
    for(i = 0; i < size; i++)
        for(j = 0; j < size; j++)
            g[i][j] = MAX;
}

int main()
{
    int i, j;
    while(scanf("%d", &n) != -1)
    {
        init_g(n);
        for(i = 0; i < n; i++)
            for(j = 0; j < n; j++)
            {
                scanf("%d", &g[i][j]);
                if(!g[i][j]) g[i][j] = MAX;
            }
        printf("%d\n", mini_spanning_tree(n, g));
    }

    return 0;
}