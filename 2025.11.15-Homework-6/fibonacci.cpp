#include <stdio.h>

long long fibonacci(int n);

int main(int argc, char** argv)
{
    int n = 0;
    scanf("%d", &n);
    
    long long res = 0;
    res = fibonacci(n);
    printf("%lld", res);
    
    return 0;
}

long long fibonacci(int n) // Определение
{
    if (n == 0) return 1;
    if (n == 1) return 1;
    
    long long a = 1;
    long long b = 1;
    long long c;
    
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    
    return b;
}