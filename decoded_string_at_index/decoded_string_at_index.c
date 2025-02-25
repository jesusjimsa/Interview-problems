/*
    You are given an encoded string `s`. To decode the string to a tape, the encoded string is read one character at a
    time and the following steps are taken:

    * If the character read is a letter, that letter is written onto the tape.
    * If the character read is a digit `d`, the entire current tape is repeatedly written `d - 1` more times in total.

    Given an integer k, return the kth letter (1-indexed) in the decoded string.

    ## Example 1:
    ```
    Input: s = "leet2code3", k = 10
    Output: "o"
    Explanation: The decoded string is "leetleetcodeleetleetcodeleetleetcode".
    The 10th letter in the string is "o".
    ```

    ## Example 2:
    ```
    Input: s = "ha22", k = 5
    Output: "h"
    Explanation: The decoded string is "hahahaha".
    The 5th letter is "h".
    ```

    ## Example 3:
    ```
    Input: s = "a2345678999999999999999", k = 1
    Output: "a"
    Explanation: The decoded string is "a" repeated 8301530446056247680 times.
    The 1st letter is "a".
    ```

    ## Constraints:

    * `2 <= s.length <= 100`
    * `s` consists of lowercase English letters and digits `2` through `9`.
    * `s` starts with a letter.
    * `1 <= k <= 10^9`
    * It is guaranteed that `k` is less than or equal to the length of the decoded string.
    * The decoded string is guaranteed to have less than `2^63` letters.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* decodeAtIndex(char* s, int k) {
    const unsigned int MAX_K = 1000000000;
    char *decoded = (char *)malloc(MAX_K * sizeof(char));
    char *solution = (char *)malloc(sizeof(char)*2);
    int length_so_far = 0;
    int i = 0;
    int j = 0;

    if (!decoded || !solution) {
        return NULL;
    }

    for (i = 0; i < strlen(s); i++) {
        if (isalpha(s[i])) {
            snprintf(decoded, length_so_far + 2, "%s%c", decoded, s[i]);
            length_so_far++;
        }
        else {
            char *to_concatenate = (char*)malloc(length_so_far * sizeof(char));
            int extra_length = length_so_far;

            // strcpy(to_concatenate, decoded);
            snprintf(to_concatenate, length_so_far + 1, "%s", decoded);

            for (j = 0; j < atoi(&s[i]) - 1; j++) {
                strcat(decoded, to_concatenate);
                length_so_far += extra_length;
            }

            free(to_concatenate);
        }

        if (length_so_far >= k) {
            // strcpy(solution, &decoded[k-1]);
            snprintf(solution, 2, "%c", decoded[k-1]);
            free(decoded);
            return solution;
        }
    }

    if (decoded) {
        free(decoded);
    }

    if (solution) {
        free(solution);
    }

    return NULL;
}

int main(int argc, char const *argv[]) {
    char *s = "leet2code3";
    int k = 10;

    printf("Solution: %s\n", decodeAtIndex(s, k));

    char *s2 = "ha22";
    k = 5;

    printf("Solution: %s\n", decodeAtIndex(s2, k));
    
    char *s3 = "a2345678999999999999999";
    k = 1;

    printf("Solution: %s\n", decodeAtIndex(s3, k));

    return 0;
}
