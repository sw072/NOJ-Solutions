#include "stdio.h"
#include "math.h"

#define pi 3.141592653

double L, Lx, hL, hLx;
double t[50][50];

double f(double h, double x)
{
    double temp = pi * h * cos(pi * x / Lx) / Lx;
    return sqrt(1 + temp * temp);
}

double integration(double h)
{
    int idx, i, j, n;
    double d;
    t[1][0] = hLx * (f(h, 0) + 1) / 2;
    idx = 1;
    do{
        t[1][idx] = 0;
        n = 1 << idx;
        d = hLx / n;
        for(i = 1; i < n; i++)
            t[1][idx] += f(h, i * d);
        t[1][idx] = f(h, 0) + t[1][idx] * 2 + 1;
        t[1][idx] *= (d / 2);
        for(i = 2; i <= idx + 1; i++)
        {
            j = idx - i + 1;
            t[i][j] = ((4 << (i - 1)) * t[i - 1][j + 1] - t[i - 1][j]) / ((4 << (i - 1)) - 1);
        }
        idx++;
    }while(fabs(t[idx][0] - t[idx - 1][0]) > 0.000005);
    return t[idx][0];
}

double find()
{
    double low = 0;
    double high = 5000;
    double mid = 0;
    double interg = 0;
    while(low < high)
    {
        mid = (low + high) / 2;
        interg = integration(mid);
        if(interg - hL > 0.000005)
            high = mid;
        else if(hL - interg > 0.000005)
            low = mid;
        else break;
    }
    return mid;
}

int main()
{
    while(scanf("%lf%lf", &L, &Lx) != -1)
    {
        hL = L / 2;
        hLx = Lx / 2;
        printf("%.3f\n", find());
    }

    return 0;
}