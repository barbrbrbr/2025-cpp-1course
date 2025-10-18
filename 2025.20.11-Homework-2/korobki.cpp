#include <cstdio>

int main()
{
    int a1 = 0;
    int b1 = 0;
    int c1 = 0;
    int a2 = 0;
    int b2 = 0;
    int c2 = 0;
    scanf("%d %d %d", &a1, &b1, &c1);
    scanf("%d %d %d", &a2, &b2, &c2);

    if (a1 > b1) 
    { 
        int m = a1; a1 = b1; b1 = m; 
    }
    if (b1 > c1) 
    { 
        int m = b1; b1 = c1; c1 = m; 
    }
    if (a1 > b1) 
    { 
        int m = a1; a1 = b1; b1 = m; 
    }
    
    if (a2 > b2)
    { 
        int m = a2; a2 = b2; b2 = m; 
    }
    if (b2 > c2) 
    { 
        int m = b2; b2 = c2; c2 = m; 
    }
    if (a2 > b2) 
    { 
        int m = a2; a2 = b2; b2 = m; 
    }
    
    if (a1 == a2 && b1 == b2 && c1 == c2) 
    {
        printf("Boxes are equal");
    }
    else if (a1 <= a2 && b1 <= b2 && c1 <= c2) 
    {
        printf("The first box is smaller than the second one");
    }
    else if (a2 <= a1 && b2 <= b1 && c2 <= c1) 
    {
        printf("The first box is larger than the second one");
    }
    else 
    {
        printf("Boxes are incomparable");
    }

    return 0;
}