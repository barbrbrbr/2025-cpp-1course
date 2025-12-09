#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) {

    char data[100];
    fgets(data, sizeof(data), stdin);

    data[strcspn(data, "\n")] = '\0';


    char* token;
    char* long_w = NULL;
    int max_l = 0;
    
    token = strtok(data, " ");

    while (token != NULL) {
        int len = strlen(token);

        if (len > max_l) {
            max_l = len;
            long_w = token;
        }

        token = strtok(NULL, " ");
    }

    if (long_w != NULL) {
        printf("%s\n %d\n", long_w, max_l);
    }

    return 0;
}
