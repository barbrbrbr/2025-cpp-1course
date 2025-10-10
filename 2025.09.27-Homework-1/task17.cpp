#include <cstdio>
int main() 
{
    long long a = 0;
	scanf("%lld", &a);
    printf("%lld", (a % 100) / 10);
    return 0;
}