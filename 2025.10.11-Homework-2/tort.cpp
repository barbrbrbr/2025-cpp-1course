#include <cstdio>

int main()
{
    int a = 0;
    scanf("%d", &a);

    if (a == 1) {
        printf("%d", 0);
    }
    else if (a == 2) {
        printf("%d", 1);
    }
    else if (a == 3) {
        printf("%d", 3);
    }
    else if (a % 2 == 0) 
    {
        printf("%d", a/2);
    }
    else
    {
        printf("%d", a);
    }
    return 0;
}
