#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 0;
    int b = 0;
    int c = 0;
    scanf("%d %d %d", &a, &b, &c);
    
    if (a != 0) 
    {
        printf("%d", a);
    }
    
    if (b != 0) {
        if (a != 0) 
        {
            if (b > 0) 
            {
                printf("+");
            }
        }
        if (abs(b) == 1) 
        {
            if (b == -1) 
            {
                printf("-");
            }
        } else 
        {
            printf("%d", b);
        }
        printf("x");
    }
    
    if (c != 0) 
    {
        if (a != 0 || b != 0) 
        {
            if (c > 0) 
            {
                printf("+");
            }
        }
        if (abs(c) == 1) 
        {
            if (c == -1) 
            {
                printf("-");
            }
        } else {
            printf("%d", c);
        }
        printf("y");
    }
    
    if (a == 0 && b == 0 && c == 0) 
    {
        printf("0");
    }
    
    return 0;
}