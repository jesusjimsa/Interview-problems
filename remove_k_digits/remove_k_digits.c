/**
    Given string `num` representing a non-negative integer `num`, and an integer `k`, return the smallest possible
    integer after removing `k` digits from `num`.

    ### Example 1:

    ```
    Input: num = "1432219", k = 3
    Output: "1219"
    ```

    Explanation: Remove the three digits `4`, `3`, and `2` to form the new number `1219` which is the smallest.

    ### Example 2:

    ```
    Input: num = "10200", k = 1
    Output: "200"
    ```

    Explanation: Remove the leading `1` and the number is `200`. Note that the output must not contain leading zeroes.

    ### Example 3:

    ```
    Input: num = "10", k = 2
    Output: "0"
    ```

    Explanation: Remove all the digits from the number and it is left with nothing which is `0`.
    

    ## Constraints:

    * `1 <= k <= num.length <= 10^5`
    * `num` consists of only digits.
    * `num` does not have any leading zeros except for the zero itself.
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

char* removeKdigits(char* num, int k) {
    const int num_len = strlen(num);

    if (k >= num_len) {
        return "0";
    }

    char *solution = (char*)malloc(sizeof(char) * (num_len - k + 1));
    char *tmp_string = (char*)malloc(sizeof(char) * (num_len + 1));
    int min = __INT_MAX__;
    int tmp_value = 0;
    int i = 0;
    int j = 0;
    
    snprintf(tmp_string, sizeof(tmp_string), "%s", num);

    for (i = 0; i < num_len - k + 1; i++) {
        for (j = i; j < (i + k) && j < num_len; j++) {
            remove_char_at(tmp_string, i);
        }

        sscanf(tmp_string, "%d", &tmp_value);

        if (tmp_value < min) {
            min = tmp_value;
        }

        snprintf(tmp_string, sizeof(tmp_string), "%s", num);
    }

    snprintf(solution, num_len - k + 1, "%d", min);
    // sprintf(solution, "%d", min);

    if (tmp_string) {
        free(tmp_string);
    }

    return solution;
}

int main(int argc, char const *argv[]) {
    printf("%s\n", removeKdigits("1432219", 3));
    printf("%s\n", removeKdigits("10200", 1));
    printf("%s\n", removeKdigits("10", 2));
    printf("%s\n", removeKdigits("112", 1));

    return 0;
}

