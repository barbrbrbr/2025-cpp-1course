#include <stdio.h>

int C(int n, int k);

int main(int argc, char** argv)
{
    int n, k;
    scanf("%d %d", &n, &k);
    
    int result = C(n, k);
    printf("%d\n", result);
    
    return 0;
}

int C(int n, int k)
{
    if (k == 0 || k == n) {
        return 1;
    }
    
    return C(n - 1, k - 1) + C(n - 1, k);
}