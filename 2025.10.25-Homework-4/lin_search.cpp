#include <cstdio>

#define size 1000

int main() {
    int n = 0;
    scanf("%d", &n);
    
    int A[size];
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    
    int x = 0;
    scanf("%d", &x);
    
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (A[i] == x) {
            count++;
        }
    }
    
    printf("%d", count);
    
    return 0;
}