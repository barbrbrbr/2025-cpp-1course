#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) {

    char data[100];
    fgets(data, sizeof(data), stdin);

    char* token;
    int count = 0;
    
    token = strtok(data, " ");

    while (token != NULL) {
        count ++;
        token = strtok(NULL, " ");
    }
    printf("%d", count);

    return 0;
}
