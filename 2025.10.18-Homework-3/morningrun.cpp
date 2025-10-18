#include <cstdio>

int main()
{
    double a = 0;
    double b = 0;
    int count = 1;

    scanf("%lf %lf", &a, &b);

    while (a < b) {
        a = (a * 115) / 100;
        count++;
    }
    printf("%d", count);

    return 0;
}
