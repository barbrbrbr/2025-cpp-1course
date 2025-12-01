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
    
    for (int i = 1; i < n - 1; i++) {
        if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
            cnt++;
        }
    }
    
    printf("%d\n", cnt);

    return 0;
}
