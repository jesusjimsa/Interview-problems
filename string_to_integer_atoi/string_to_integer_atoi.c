/*
    Implement the `myAtoi(string s)` function, which converts a string to a 32-bit signed integer.

    The algorithm for `myAtoi(string s)` is as follows:

    1. **Whitespace**: Ignore any leading whitespace (`" "`).
    2. **Signedness**: Determine the sign by checking if the next character is `'-'` or `'+'`, assuming positivity if
        neither present.
    3. **Conversion**: Read the integer by skipping leading zeros until a non-digit character is encountered or the end
        of the string is reached. If no digits were read, then the result is 0.
    4. **Rounding**: If the integer is out of the 32-bit signed integer range `[-2^31, 2^31 - 1]`, then round the
        integer to remain in the range. Specifically, integers less than `-2^31` should be rounded to `-2^31`, and
        integers greater than `2^31 - 1` should be rounded to `2^31 - 1`.

    Return the integer as the final result.

    ## Example 1:
    ```
    Input: s = "42"

    Output: 42

    Explanation:

    The underlined characters are what is read in and the caret is the current reader position.
    Step 1: "42" (no characters read because there is no leading whitespace)
            ^
    Step 2: "42" (no characters read because there is neither a '-' nor '+')
            ^
    Step 3: "42" ("42" is read in)
            ^
    ```

    ## Example 2:
    ```
    Input: s = " -042"

    Output: -42

    Explanation:

    Step 1: "   -042" (leading whitespace is read and ignored)
                ^
    Step 2: "   -042" ('-' is read, so the result should be negative)
                ^
    Step 3: "   -042" ("042" is read in, leading zeros ignored in the result)
                ^
    ```

    ## Example 3:
    ```
    Input: s = "1337c0d3"

    Output: 1337

    Explanation:

    Step 1: "1337c0d3" (no characters read because there is no leading whitespace)
            ^
    Step 2: "1337c0d3" (no characters read because there is neither a '-' nor '+')
            ^
    Step 3: "1337c0d3" ("1337" is read in; reading stops because the next character is a non-digit)
                ^
    ```

    ## Example 4:
    ```
    Input: s = "0-1"

    Output: 0

    Explanation:

    Step 1: "0-1" (no characters read because there is no leading whitespace)
            ^
    Step 2: "0-1" (no characters read because there is neither a '-' nor '+')
            ^
    Step 3: "0-1" ("0" is read in; reading stops because the next character is a non-digit)
            ^
    ```

    ## Example 5:
    ```
    Input: s = "words and 987"

    Output: 0

    Explanation:

    Reading stops at the first non-digit character 'w'.
    ```

    ## Constraints:

    * `0 <= s.length <= 200`
    * `s` consists of English letters (lower-case and upper-case), digits (`0-9`), `' '`, `'+'`, `'-'`, and `'.'`.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

bool is_letter(char mander) {
    if ((mander >= 'a' && mander <= 'z') || (mander >= 'A' && mander <= 'Z')) {
        return true;
    }

    return false;
}

bool is_number(char mander) {
    if (mander >= '0' && mander <= '9') {
        return true;
    }

    return false;
}

int myAtoi(char* s) {
    bool is_negative = false;
    bool symbol_changed = false;
    bool first_num = true;
    int s_len = strlen(s);
    long long result = 0;
    int multiply = 1;
    int i = 0;

    for (i = 0; i < s_len; i++) {
        if (is_letter(s[i]) || s[i] == '.') {
            break;
        }

        if (first_num && s[i] == '-' && !symbol_changed) {
            is_negative = true;
            symbol_changed = true;
            continue;
        }

        if (first_num && s[i] == '+' && !symbol_changed) {
            is_negative = false;
            symbol_changed = true;
            continue;
        }

        if ((!first_num || symbol_changed) && (s[i] == '+' || s[i] == '-' || s[i] == ' ')) {
            break;
        }

        if (is_number(s[i])) {
            if (result * multiply > INT_MAX) {    // Overflow
                return is_negative ? INT_MIN : INT_MAX;
            }

            result *= multiply;
            result += s[i] - '0';

            multiply = 10;
            first_num = false;
        }
    }

    if (is_negative) {
        result *= -1;
    }

    return (int)result;
}

int main(int argc, char const *argv[]) {
    char test1[] = "42";
    char test2[] = " -042";
    char test3[] = "1337c0d3";
    char test4[] = "0-1";
    char test5[] = "words and 987";
    char test6[] = "+987";
    char test7[] = "+-987";

    printf("%d\n", myAtoi(test1));
    printf("%d\n", myAtoi(test2));
    printf("%d\n", myAtoi(test3));
    printf("%d\n", myAtoi(test4));
    printf("%d\n", myAtoi(test5));
    printf("%d\n", myAtoi(test6));
    printf("%d\n", myAtoi(test7));

    return 0;
}
