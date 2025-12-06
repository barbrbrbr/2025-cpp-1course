#include <stdio.h>
#include <stdbool.h>

bool election(int x, int y, int z); 

int main(int argc, char** argv)
{
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);

    int result = election(x, y, z);
    printf("%d\n", result);
    
    return 0;
}

bool election(int x, int y, int z)
{
    return (x + y + z) >= 2;
}