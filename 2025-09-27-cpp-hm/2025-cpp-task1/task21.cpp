#include <stdio.h>
#include <iostream>

int main() 
{
    long long a = 0, 
    long long b = 0; 
    long long c = 0;
	scanf("%lld", &a, &b);
    //char *c = (a % b == 0 || b % a == 0) ? "1" : "456";    
    c = (a%b) * (b%a) + 1;
    printf("%d\n", c);
    return 0;
}