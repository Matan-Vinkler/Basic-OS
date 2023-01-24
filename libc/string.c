#include "string.h"
#include "../cpu/type.h"

void int_to_ascii(int n, char str[])
{
    int i = 0, sign = n;
    if(sign < 0)
    {
        n = -n;
    }

    str[i] = '\0';

    do
    {
        str[i++] = n % 10 + '0';
        n /= 10;
    } while (n > 0);

    if(sign < 0)
    {
        str[i++] = '-';
    }

    reverse(str);
}

void hex_to_ascii(int n, char str[])
{
    append(str, '0');
    append(str, 'x');

    char zeros = 0;

    int32_t temp;
    int i;

    for(i = 28; i > 0; i -= 4)
    {
        temp = (n >> i) & 0xF;

        if(temp == 0 && zeros == 0)
        {
            continue;
        }

        zeros = 1;

        if(temp > 0xA)
        {
            append(str, temp - 0xA + 'A');
        }
        else
        {
            append(str, temp + '0');
        }
    }

    temp = n & 0xF;
    if(temp >= 0xA)
    {
        append(str, temp - 0xA + 'A');
    }
    else
    {
        append(str, temp + '0');
    }
}

void reverse(char s[])
{
    int c, i ,j;
    for(i = 0, j = strlen(s) - 1; i < j; i++, j--)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

int strlen(char s[])
{
    int i = 0;
    while(s[i] != 0)
    {
        i++;
    }

    return i;
}

void backspace(char s[])
{
    int len = strlen(s);
    s[len - 1] = '\0';
}

void append(char s[], char n)
{
    int len = strlen(s);
    s[len] = n;
    s[len + 1] = '\0';
}

int strcmp(char s1[], char s2[])
{
    int i;
    for(i = 0; s1[i] == s2[i]; i++)
    {
        if(s1[i] == '\0')
        {
            return 0;
        }
    }

    return s1[i] - s2[i];
}