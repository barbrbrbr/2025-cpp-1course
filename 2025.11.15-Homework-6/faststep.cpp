#include <stdio.h>

double power(double a, int n); 

int main(int argc, char** argv)
{
    double a = 0;
    int n = 0;
    
    scanf("%lf %d", &a, &n);
    
    double res = power(a, n);
    printf("%g", res);
    
    return 0;
}

double power(double a, int n) 
{
    double res = 1.0;

    while (n>0) {
        if (n % 2 == 1) {
            res *= a;
        }
        a *= a;
        n /= 2;
    }
    return res;
}