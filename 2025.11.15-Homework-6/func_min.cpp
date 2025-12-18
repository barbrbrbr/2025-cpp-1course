#include <stdio.h>

int min(int a, int b, int c, int d); // (объявление)

int main(int argc, char** argv)
{
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    
    scanf("%d %d %d %d", &a, &b, &c, &d);
    
    int res = 0;
    res = min(a, b, c, d);
    printf("%d\n", res);
    
    return 0;
}

int min(int a, int b, int c, int d) 
{
    int minimum = a;
    
    if (b < minimum) {
        minimum = b;
    }
    if (c < minimum) {
        minimum = c;
    }
    if (d < minimum) {
        minimum = d;
    }
    
    return minimum;
}