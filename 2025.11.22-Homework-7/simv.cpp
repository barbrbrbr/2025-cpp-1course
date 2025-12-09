#include <stdio.h>

int IsDigit(unsigned char c);

int main(int argc, char** argv)
{
    unsigned char c = 0;
    scanf("%c", &c);
    
    if (IsDigit(c)) {
        printf("yes");
    } else {
        printf("no");
    }
    
    return 0;
}

int IsDigit(unsigned char c)
{
    return (c >= '0' && c <= '9');
}