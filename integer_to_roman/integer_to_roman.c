/**
    Roman numerals are represented by seven different symbols: `I`, `V`, `X`, `L`, `C`, `D` and `M`.

    ```
    Symbol       Value
    I             1
    V             5
    X             10
    L             50
    C             100
    D             500
    M             1000
    ```

    For example, `2` is written as `II` in Roman numeral, just two one's added together. `12` is written as `XII`, which is simply` X + II`. The number `27` is written as `XXVII`, which is `XX + V + II`.

    Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not `IIII`. Instead, the number four is written as `IV`. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as `IX`. There are six instances where subtraction is used:

    * `I` can be placed before `V` (`5`) and `X` (`10`) to make `4` and `9`.
    * `X` can be placed before `L` (`50`) and `C` (`100`) to make `40` and `90`.
    * `C` can be placed before `D` (`500`) and `M` (`1000`) to make `400` and `900`.

    Given an integer, convert it to a roman numeral.

    ### Example 1:
    ```
    Input: num = 3
    Output: "III"
    Explanation: 3 is represented as 3 ones.
    ```

    ### Example 2:
    ```
    Input: num = 58
    Output: "LVIII"
    Explanation: L = 50, V = 5, III = 3.
    ```

    ### Example 3:
    ```
    Input: num = 1994
    Output: "MCMXCIV"
    Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
    ```

    ## Constraints:

    * `1 <= num <= 3999`
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* intToRoman(int num) {
    char *solution = (char*)malloc(sizeof(char) * 25);
    int times_M = num / 1000;
    int times_C = num / 100 - times_M * 10;
    int times_X = num / 10 - times_M * 100 - times_C * 10;
    int times_I = num - times_M * 1000 - times_C * 100 - times_X * 10;
    int i = 0;

    snprintf(solution, 1, "");

    for (i = 0; i < times_M; i++) {
        strcat(solution, "M");
    }

    if (times_C == 9) {
        strcat(solution, "CM");
    }
    else if (times_C >= 5) {
        strcat(solution, "D");

        for (i = times_C; i > 5; i--) {
            strcat(solution, "C");
        }
    }
    else if (times_C == 4) {
        strcat(solution, "CD");
    }
    else {
        for (i = 0; i < times_C; i++) {
            strcat(solution, "C");
        }
    }

    if (times_X == 9) {
        strcat(solution, "XC");
    }
    else if (times_X >= 5) {
        strcat(solution, "L");

        for (i = times_X; i > 5; i--) {
            strcat(solution, "X");
        }
    }
    else if (times_X == 4) {
        strcat(solution, "XL");
    }
    else {
        for (i = 0; i < times_X; i++) {
            strcat(solution, "X");
        }
    }

    if (times_I == 9) {
        strcat(solution, "IX");
    }
    else if (times_I >= 5) {
        strcat(solution, "V");

        for (i = times_I; i > 5; i--) {
            strcat(solution, "I");
        }
    }
    else if (times_I == 4) {
        strcat(solution, "IV");
    }
    else {
        for (i = 0; i < times_I; i++) {
            strcat(solution, "I");
        }
    }

    return solution;
}

int main(int argc, char const *argv[]) {
    char *solution = intToRoman(3);

    printf("%s\n", solution);

    solution = intToRoman(58);

    printf("%s\n", solution);

    solution = intToRoman(1994);
    
    printf("%s\n", solution);

    solution = intToRoman(1997);
    
    printf("%s\n", solution);

    solution = intToRoman(3999);
    
    printf("%s\n", solution);

    if (solution) {
        free(solution);
    }

    return 0;
}

