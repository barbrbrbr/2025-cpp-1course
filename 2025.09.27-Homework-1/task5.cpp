#include <cstdio>
int main()
{
	int a = 0;
	scanf("%d", &a);
    int nextt = a + 1;
    int pr = a - 1;
	printf("The next number for the number %d is %d. The previous number for the number %d is %d.\n", a, nextt, a, pr);
	return 0;
}