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
        if (arr[i] * arr[i + 1] > 0) {
            printf("YES");
            return 0;

        }
    }
    printf("NO");
    
    return 0;
}