#include <cstdio>
#include <stdlib.h>

#define size 1000

int main() {
    int n = 0;
    scanf("%d", &n);
    
    int A[size];
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    
    int target = 0;
    scanf("%d", &target);

    int close = 0;
    close = A[0];
    int min_diff = abs(A[0] - target);
    
    for (int i = 1; i < n; i++) {
        int diff = abs(A[i] - target);
        if (diff < min_diff) {
            min_diff = diff;
            close = A[i];
        }
    }
    printf("%d\n", close);
    return 0;
}