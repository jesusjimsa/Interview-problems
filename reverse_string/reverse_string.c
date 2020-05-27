/*
Implement a function void reverse(char *str) in C or C++ which reverses a null-terminated string.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char **str) {
    int str_len = strlen(*str);
    char *tmp = (char *)malloc(sizeof(char) * str_len + 1);
    int i = 0;

    for (i = str_len; i > 0; i--) {
        tmp[str_len - i] = (*str)[i - 1];
    }

    tmp[str_len + 1] = '\0';

    *str = tmp;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Please, write the string.\n");
        return -1;
    }

    char *str = argv[1];

    reverse(&str);

    printf("%s\n", str);

    return 0;
}
