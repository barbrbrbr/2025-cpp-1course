#include <stdio.h>
#include <string.h>

char find_double_letter(char* str);

int main(int argc, char** argv)
{
    char str[1000];
    
    scanf("%s", str);
    
    char result = find_double_letter(str);
    
    printf("%c", result);
    
    return 0;
}

char find_double_letter(char* str) // Определение
{
    int count[256] = {0};
    
    for (int i = 0; str[i] != '\0'; i++) {
        count[(unsigned char)str[i]]++;
    }
    
    for (int i = 0; i < 256; i++) {
        if (count[i] == 2) {
            return (char)i;
        }
    }
    
    return '\0';
}