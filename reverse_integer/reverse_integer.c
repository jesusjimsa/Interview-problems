/**
    Given a signed 32-bit integer `x`, return `x` with its digits reversed. If reversing `x` causes the value to go
    outside the signed 32-bit integer range `[-231, 231 - 1]`, then return `0`.

    Assume the environment does not allow you to store 64-bit integers (signed or unsigned).


    ### Example 1:
    ```
    Input: x = 123
    Output: 321
    ```

    ### Example 2:
    ```
    Input: x = -123
    Output: -321
    ```

    ### Example 3:
    ```
    Input: x = 120
    Output: 21
    ```

    ## Constraints:

    * `-2^31 <= x <= 2^31 - 1`

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void remove_char_at(char *str, int index) {
    int len = strlen(str);

    // Check for valid index and empty string
    if (index < 0 || index >= len) {
        return;
    }

    // Shift remaining characters to the left
    memmove(&str[index], &str[index + 1], len - index);

    // Update null terminator
    str[len - 1] = '\0';
}


void strrev(char *str) {
    unsigned len = strlen((const char *)str);
    char a;
    int i;
    int j;

    for (i = 0, j = len - 1; i < j; i++, j--) {
        a = str[i];
        str[i] = str[j];
        str[j] = a;
    }
}

int reverse(int x) {
    int is_negative = (x < 0);

    // If the number only has one digit, there is nothing to do
    if (x < 10 && x > -10) {
        return x;
    }

    const int int_min_len = 11;
    const int int_max_len = 10;
    char *tmp_string = (char*)malloc(sizeof(char) * int_min_len + 1);
    int solution = 0;

    snprintf(tmp_string, int_min_len + 1, "%d", x);
    strrev(tmp_string); // Reverse string

    if (((strlen(tmp_string) >= int_min_len && tmp_string[strlen(tmp_string) - 1] == '-') ||
            (strlen(tmp_string) >= int_max_len)) && (tmp_string[0] - '0') > 2) {
        return 0;
    }

    if (is_negative) {
        remove_char_at(tmp_string, strlen(tmp_string) - 1);
        sscanf(tmp_string, "%d", &solution);

        // Change the symbol here, if the value is now positive, overflow has happened and we return 0
        solution = -solution;

        if (solution > 0) {
            solution = 0;
        }
    }
    else {
        sscanf(tmp_string, "%d", &solution);

        if (solution < 0) {
            solution = 0;
        }
    }

    if (tmp_string) {
        free(tmp_string);
    }

    return solution;
}

int main(int argc, char const *argv[]) {
    printf("%d\n", reverse(123));
    printf("%d\n", reverse(-123));
    printf("%d\n", reverse(120));
    printf("%d\n", reverse(1534236469));
    printf("%d\n", reverse(-2147483412));
    return 0;
}

