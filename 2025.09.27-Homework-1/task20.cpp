#include <stdio.h>

int main() 
{
    long long a = 0, 
    long long b = 0; 
    long long c = 0;
	scanf("%lld %lld", &a, &b);
    c = (a%b) * (b%a) + 1;
    printf("%d\n", c);
    return 0;
}