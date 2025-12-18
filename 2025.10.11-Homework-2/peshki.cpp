#include <cstdio>

int main()
{
    int x1 = 0;
    int y1 = 0;
    int x2 = 0;
    int y2 = 0;
    scanf("%d %d", &x1, &y1);
    scanf("%d %d", &x2, &y2);
    
    if (y1 == 1) 
    {
        printf("NO");
        return 0;
    }

    if (x1 == x2)
	{
        if (y2 == y1 + 1)
        {  
            printf("YES");
        }
        else if (y1 == 2 && y2 == y1 + 2)
		{  
            printf("YES");
        } 
		else 
		{
            printf("NO");
        }
    } 
	else 
    {
        printf("NO");
    }
    
    return 0;
}