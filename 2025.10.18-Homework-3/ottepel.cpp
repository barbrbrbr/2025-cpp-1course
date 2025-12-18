#include <cstdio>

int main()
{
    int days = 0;
    int cur = 0;
    int maxl = 0;
    
    scanf("%d", &days);

    for (int i = 0; i < days; i++) {
        int a = 0; 
        scanf("%d", &a);
    
        if (a > 0) {
            cur++;
            if (cur > maxl) {
                maxl = cur;
            }
        }
        else {
            cur = 0;
        }
    }
    
    printf("%d", maxl);
    return 0;
}