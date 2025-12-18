#include <cstdio>

#define size 1000

int main() {
    int n = 0;
    scanf("%d", &n);
    
    int A[size];
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    
    for (int i = n - 1; i >= 0; i--) {
        printf("%d ", A[i]);
    }

    return 0;
}
