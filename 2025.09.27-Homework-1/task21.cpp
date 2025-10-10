ls#include <cstdio>

int main() 
{
    long long n = 0;
    long long k = 0;
    long long person = 0;
    long long korzina = 0;
    long long grustny = 0;
	scanf("%lld %lld", &n, &k);
    person = k / n;  
    korzina = k % n;
    grustny = (n - k % n) % n;
    printf("%lld %lld %lld", person, korzina, grustny);
    return 0;
}