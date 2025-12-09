#include <stdio.h>

char to_upper(char c);

int main(int argc, char** argv)
{
    char c;
    scanf("%c", &c);
    
    printf("%c", to_upper(c));
    return 0;
}

char to_upper(char c)
{
    if (c >= 97 && c <= 122) { // Разница: 97 - 65 = 32
        return (c - 32);
    }
    return c;
}