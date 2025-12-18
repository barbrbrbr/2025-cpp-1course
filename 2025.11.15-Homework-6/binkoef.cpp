#include <stdio.h>

int C(int n, int k);

int main(int argc, char** argv)
{
    int n = 0;
    int k = 0;
    scanf("%d %d", &n, &k);
    
    int res = 0;
    res = C(n, k);
    printf("%d\n", res);
    
    return 0;
}

int C(int n, int k)
{
    if (k == 0 || k == n) {
        return 1;
    }
    
    return C(n - 1, k - 1) + C(n - 1, k);
}