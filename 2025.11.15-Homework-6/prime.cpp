#include <stdio.h>

int prime(long long n); // Прототип (объявление)

int main(int argc, char** argv)
{
    long long n = 0;
    scanf("%lld", &n);
    
    int result = prime(n);
    
    if (result) {
        printf("prime");
    } else {
        printf("composite");
    }
    
    return 0;
}

int prime(long long n) // Определение
{
    if (n <= 1) return 0;
    if (n == 2) return 1;
    if (n % 2 == 0) return 0;
    
    for (long long i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            return 0;
        }
    }
    
    return 1;
}