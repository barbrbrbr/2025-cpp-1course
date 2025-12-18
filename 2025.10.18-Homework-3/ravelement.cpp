#include <cstdio>

int main()
{
    int a = 0; 
    int num = 0;
    int count = 0;  
    int cur = 1;
    int maxl = 1;

    scanf("%d", &num);
    
    while (scanf("%d", &a) == 1 && a != 0 ) {
        if (a == num) {
            cur++;
        } 
        else {
            if (cur > maxl) {
                maxl = cur;
            }
            cur = 1;
        }
        num = a;
        if (cur > maxl) {
        maxl = cur;
        }
    }
    
    printf("%d", maxl);
    return 0;
}