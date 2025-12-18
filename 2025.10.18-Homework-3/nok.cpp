#include <stdio.h>

int main()
{
    int a = 0;
    int b = 0;
    int nok = 0;
    int nod = 0;

    scanf("%d %d", &a, &b);

    int firsta = a;
    int firstb = b;
    
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }

    nod = a;

    nok = firsta * firstb / nod;

    printf("%d", nok);

    return 0;
}