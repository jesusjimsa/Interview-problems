/*
    You are given a string `s` of lowercase English letters and an integer array `shifts` of the same length.

    Call the `shift()` of a letter, the next letter in the alphabet, (wrapping around so that `'z'` becomes `'a'`).

    * For example, `shift('a') = 'b'`, `shift('t') = 'u'`, and `shift('z') = 'a'`.

    Now for each `shifts[i] = x`, we want to shift the first `i + 1` letters of `s`, `x` times.

    Return *the final string after all such shifts to s are applied*.

    ## Example 1:
    ```
    Input: s = "abc", shifts = [3,5,9]
    Output: "rpl"
    Explanation: We start with "abc".
    After shifting the first 1 letters of s by 3, we have "dbc".
    After shifting the first 2 letters of s by 5, we have "igc".
    After shifting the first 3 letters of s by 9, we have "rpl", the answer.
    ```

    ## Example 2:
    ```
    Input: s = "aaa", shifts = [1,2,3]
    Output: "gfd"
    ```

    ## Constraints:

    * `1 <= s.length <= 10^5`
    * `s` consists of lowercase English letters.
    * `shifts.length == s.length`
    * `0 <= shifts[i] <= 10^9`
*/

#include <stdio.h>
#include <stdlib.h>

#define ALPHABET_SIZE   26

char shift(const char letter, const long long shifts) {
    const char base = 'a';

    return (letter - base + shifts) % ALPHABET_SIZE + base;
}

char* shiftingLetters(char* s, int* shifts, int shiftsSize) {
    int i = 0;
    long long num_shifts = 0;
    char *solution = (char*)malloc(shiftsSize * sizeof(char) + 1);

    if (!solution) {
        return NULL;
    }

    for (i = shiftsSize - 1; i >= 0; i--) {
        num_shifts += shifts[i];
        solution[i] = shift(s[i], num_shifts);
    }

    solution[shiftsSize] = '\0';

    return solution;
}

int main(int argc, char const *argv[]) {
    char *s = "abc";
    int shifts[] = {3, 5, 9};
    char *sol = shiftingLetters(s, shifts, sizeof(shifts)/sizeof(int));

    printf("%s becomes %s\n", s, sol);

    free(sol);

    return 0;
}
