#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int compare(char* s1, char* s2);

int main(int argc, char** argv)
{
    char s1[50];
    char s2[50];
    
    scanf("%s %s", s1, s2);
    
    int result = compare(s1, s2);
    
    if (result) {
        printf("yes");
    } else {
        printf("no");
    }
    
    return 0;
}

int compare(char* s1, char* s2)
{
    return strcmp(s1, s2) == 0;
}