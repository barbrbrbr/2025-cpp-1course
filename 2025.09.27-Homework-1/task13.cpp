#include <cstdio>
int main()
{
	long long a = 0;
	long long b = 0;
    scanf("%lld %lld", &a, &b);
	long long res = (a*b) - (a + b - 1) + 1;
    printf("%lld", res);
    return 0;
}
