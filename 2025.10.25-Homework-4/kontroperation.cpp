#include <cstdio>

#define size 1000

int main() {
    int n = 0;
    scanf("%d", &n);
    
    int A[size];
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    
    int max = A[0];
    int min = A[0];
    for (int i = 0; i < n; i++) {
        if (A[i] > max) {
            max = A[i];
        }
        if (A[i] < min) {
            min = A[i];
        }
    }
    for (int i = 0; i < n; i++) {
        if (A[i] == max) {
            A[i] = min;
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }

    return 0;
}