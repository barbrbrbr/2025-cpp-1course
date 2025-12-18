#include <cstdio>

int main()
{
    int num1 = 0;
    int num2 = 0;
    int num3 = 0;
    int num4 = 0;
    int num5 = 0;
    int num6 = 0;

    scanf("%1d%1d%1d%1d%1d%1d", &num1, &num2, &num3, &num4, &num5, &num6);
    
    if (num1 + num2 + num3 == num4 + num5 + num6)
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }
    
    return 0;
}