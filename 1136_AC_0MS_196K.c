#include "stdio.h"
#include "string.h"

void BinaryToGray(char code[], int len)
{
    char graycode[101];
    int i;
    graycode[0] = code[0];
    for(i = 1; i < len; i++)
    {
        if(code[i] == code[i-1]) graycode[i] = '0';
        else graycode[i] = '1';
    }
    graycode[i] = 0;
    printf("%s\n", graycode);
}

void GrayToBinary(char code[], int len)
{
    char binarycode[101];
    int i;
    binarycode[0] = code[0];
    for(i = 1; i < len; i++)
    {
        if(code[i] == binarycode[i-1]) binarycode[i] = '0';
        else binarycode[i] = '1';
    }
    binarycode[i] = 0;
    printf("%s\n", binarycode);
}

int main()
{
    char code[101];
    int len;
    char type;
    while(scanf("%s %c", code, &type) != -1)
    {
        len = strlen(code);
        if(len == 1 && code[0] == '0' && type == '0') break;
        if(type == 'B')
            BinaryToGray(code, len);
        else if(type == 'G')
            GrayToBinary(code, len);
    }

    return 0;
}