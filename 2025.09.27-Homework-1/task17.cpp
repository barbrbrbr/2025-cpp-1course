#include <stdio.h>
int main() 
{
    long long a = 0;
	scanf("%lld", &a);
    printf("%lld\n", (a%100)/10);
    return 0;
}