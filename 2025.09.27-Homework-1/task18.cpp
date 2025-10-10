#include <cstdio>
int main() 
{
    long long a = 0;
    long long b = 0;
    long long c = 0;
    long long d = 0;
	scanf("%lld", &a);
    b = a/100;
    c = (a%100)/10;
    d = a%10;
    printf("%lld", b+c+d);
    return 0;
}