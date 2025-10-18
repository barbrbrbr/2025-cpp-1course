#include <cstdio>

int main()
{
    int n = 0;
    scanf("%d", &n);

    int a = 0;
    int b = 0;
    b = 1;
    int t = 1;
    if (n == 0) {
        printf("0");
        return 0;

    }
    if (n == 1) {
        printf("1");
        return 0;

    }
    while (t < n) {
        int chisl = a + b;
        a = b;
        b = chisl;
        t = t + 1;
    }
    printf("%d", b);
    return 0;
}