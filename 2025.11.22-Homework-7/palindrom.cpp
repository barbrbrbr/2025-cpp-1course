#include <stdio.h>
#include <string.h>

int is_palindrome(char* str);

int main(int argc, char** argv)
{
    char str[100];
    
    scanf("%s", str);
    
    int res = 0;
    res = is_palindrome(str);
    
    if (res) {
        printf("yes");
    } else {
        printf("no");
    }
    
    return 0;
}

int is_palindrome(char* str)
{
    int len = strlen(str);
    
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - 1 - i]) {
            return 0;
        }
    }
    
    return 1;
}