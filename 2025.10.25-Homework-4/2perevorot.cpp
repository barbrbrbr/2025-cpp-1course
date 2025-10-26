#include <stdio.h>

#define MAX_SIZE 1000

int main() {
    int n = 0;
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    scanf("%d %d %d %d %d", &n, &a, &b, &c, &d);
    
    int arr[MAX_SIZE];
    
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }
    
    int start1 = a - 1;
    int end1 = b - 1;
    while (start1 < end1) {
        int temp = arr[start1];
        arr[start1] = arr[end1];
        arr[end1] = temp;
        start1++;
        end1--;
    }
    
    // Второй переворот от C до D (переводим в 0-индексацию)
    int start2 = c - 1;
    int end2 = d - 1;
    while (start2 < end2) {
        int temp = arr[start2];
        arr[start2] = arr[end2];
        arr[end2] = temp;
        start2++;
        end2--;
    }
    
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}