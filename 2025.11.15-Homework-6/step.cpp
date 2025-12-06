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
    if (n == 0) return 1.0;
    if (a == 0.0) return 0.0;
    double power = 1.0;
    for (int i = 0; i < n; i++) {
        power *= a;
    }
    
    return power;
}