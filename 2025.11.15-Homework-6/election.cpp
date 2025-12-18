#include <stdio.h>
#include <stdbool.h>

bool election(int x, int y, int z); 

int main(int argc, char** argv)
{
    int x = 0;
    int y = 0;
    int z = 0;
    scanf("%d %d %d", &x, &y, &z);

    int res = 0;
    res = election(x, y, z);
    printf("%d\n", res);
    
    return 0;
}

bool election(int x, int y, int z)
{
    return (x + y + z) >= 2;
}