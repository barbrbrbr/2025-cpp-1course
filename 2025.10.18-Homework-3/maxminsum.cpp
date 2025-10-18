#include <cstdio>

int main()
{
    int a = 0; 
    int count = 0;   
    int me = 0; // maxeven
    int mo = 0; // minodd
    int first_even = 1; 
    int first_odd = 1;
    
    while (scanf("%d", &a) == 1) {
        count++;
        
        if (count % 2 == 0) {
            if (first_even) {
                me = a;
                first_even = 0;
            }
            else if (a > me) {
                me = a;
            }
        }
        else {
            if (first_odd) {
                mo = a;
                first_odd = 0;
            }
            else if (a < mo) {
                mo = a;
            }
        }
    }
    
    int res = me + mo;
    printf("%d", res);
    
    return 0;
}