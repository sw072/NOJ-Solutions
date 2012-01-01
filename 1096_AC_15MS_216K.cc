#include "stdio.h"
#include "math.h"

float e = 2.718281828;

float TD(float t, float d)
{
    return t + 0.5555*(6.11 * pow((double)e, 5417.7530 * (1/273.16 - 1 / (d + 273.16))) - 10);
}

float TH(float t, float h)
{
    return 1 / (1 / 273.16 - log((10 + (h - t) / 0.5555) / 6.11) / 5417.7530) - 273.16;
}

float HD(float h, float d)
{
    return h - 0.5555*(6.11 * pow((double)e, 5417.7530 * (1/273.16 - 1 / (d + 273.16))) - 10);
}

int main()
{
    float T, H, D;
    bool tf, hf, df;
    char c;
    int i;
    while(1)
    {
        tf = hf = df = false;
        scanf("%c", &c);
        if(c == 'E') break;
        for(i = 0; i < 2; i++)
        {
            if(c == 'T')
            {
                scanf(" %f", &T);
                tf = true;
            }
            else if(c == 'H')
            {
                scanf(" %f", &H);
                hf = true;
            }
            else if(c == 'D')
            {
                scanf(" %f", &D);
                df = true;
            }
            scanf("%c", &c);
            if(!i)
                scanf("%c", &c);
        }
        if(tf == false) printf("T %.1f D %.1f H %.1f\n", HD(H, D), D, H);
        if(hf == false) printf("T %.1f D %.1f H %.1f\n", T, D, TD(T, D));
        if(df == false) printf("T %.1f D %.1f H %.1f\n", T, TH(T, H), H);
    }

    return 0;
}