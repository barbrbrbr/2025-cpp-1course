#include <cstdio>
int main()
{
	long long v = 0;
	long long t = 0;
    scanf("%lld %lld", &v, &t);
	long long res = ( (v * t % 109 + 109) % 109 + 1 );
    printf("%lld", res);
    return 0;
}
