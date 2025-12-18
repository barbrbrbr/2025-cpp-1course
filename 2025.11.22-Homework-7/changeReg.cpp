#include <stdio.h>

char ch_reg(char c);

int main(int argc, char** argv)
{
    char c = 0;
    scanf("%c", &c);
    
    printf("%c", ch_reg(c));
    return 0;
}

char ch_reg(char c)
{
    if (c >= 97 && c <= 122) {
        return (c - 32);
    }
    else if (c >= 65 && c <=  90) {
        return (c + 32);
    }
    return c;

}