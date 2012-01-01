#include "stdio.h"
#include "string.h"

#define N 101
#define low_bit(index) (index & (index ^ (index - 1)))
long long c[N][N][N];
int size;
int length;

//int low_bit(int index)
//{
//    return index & (index ^ (index - 1));
//}

void add(int x, int y, int z, int val)
{
   for(int i = x; i <= length; i += low_bit(i))  
        for(int j = y; j <= length; j += low_bit(j))  
            for(int k = z; k <= length; k += low_bit(k))
            {  
                c[i][j][k] += val;  
            }  
}

long long query(int x, int y, int z)
{
    long long sum = 0;
    if(x < 1 || y < 1 || z < 1) return 0;
    for(int i = x; i > 0; i -= low_bit(i))  
        for(int j = y; j > 0; j -= low_bit(j))  
            for(int k = z; k > 0; k -= low_bit(k))
            {  
                sum += c[i][j][k];
            }
    return sum;
}

int main()
{
    int x, y, z, x1, y1, z1, val;
    long long sum;
    char command;
    while(scanf("%d\n", &size) != -1)
    {
        length = size;
        memset(c, 0, sizeof(c));
        while(scanf("%c", &command))
        {
            if(command == '0')
                break;
            if(command == 'A')
            {
                scanf("%d%d%d%d\n", &x, &y, &z, &val);
                add(x, y, z, val);
            }
            else if(command == 'S')
            {
                scanf("%d%d%d%d\n", &x, &y, &z, &val);
                add(x, y, z, 0 - val);
            }
            else if(command == 'Q')
            {
                scanf("%d%d%d", &x, &y, &z);
                scanf("%d%d%d\n", &x1, &y1, &z1);
                printf("%d\n", query(x1, y1, z1) - query(x - 1, y1, z1) 
                    - query(x1, y - 1, z1) - query(x1, y1, z - 1) 
                    + query(x - 1, y1, z - 1) + query(x1, y - 1, z - 1)
                    + query(x - 1, y - 1, z1) - query(x - 1, y - 1, z - 1));
            }
        }
    }

    return 0;
}