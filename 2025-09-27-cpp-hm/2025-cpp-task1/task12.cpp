#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
    long long a = 0; //10^9
    long long b = 0;
    long long c = 0;
	scanf("%d %d %d", &a, &b, &c);
    long long f = 0;
    f = a + b + c;
	printf("%lld\n", f);
	return 0;
}