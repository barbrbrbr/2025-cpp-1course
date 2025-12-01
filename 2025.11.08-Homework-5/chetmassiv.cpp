#include <stdio.h>
#define arr_size 10000

int main() 
{
    
    int n = 0;
    scanf("%d", &n);
    
    int arr[arr_size];
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            printf("%d ", arr[i]);
        }
    }
    return 0;
}