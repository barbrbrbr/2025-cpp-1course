#include <cstdio>

int main()
{
    int a = 0; 
    int first_m = 0;
    int sec_m = 0;

    while (scanf("%d", &a) == 1 && a != 0 ) {
        if (a > first_m) {
        sec_m = first_m;
        first_m = a;
        }
        else if (a > sec_m ) {
            sec_m = a;
        }
    }

printf("%d", sec_m);

return 0;
}