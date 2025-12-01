#include <stdio.h>
#define arr_size 10000

int main() 
{
    
    int n = 0;
    scanf("%d", &n);

    int cnt = 0;
    
    int arr[arr_size];
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    for (int i = 0; i < n / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = temp;
    }
        
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}