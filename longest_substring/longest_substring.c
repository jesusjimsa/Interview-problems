/**
 * Given a string, find the length of the longest substring without repeating characters.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true    1 == 1
#define false   !(true)

void empty_visited_array(char visited[], const int len) {
    int i = 0;

    for (i = 0; i < len; i++) {
        visited[i] = '\0';
    }
}

int was_visited(const char letter, const char visited[], const int len) {
    int i = 0;

    for (i = 0; i < len; i++) {
        if (letter == visited[i]) {
            return true;
        }
    }

    return false;
}

int max(int first, int second) {
    return first > second ? first : second;
}

int lengthOfLongestSubstring(const char* s) {
    const int s_len = strlen(s);

    if (s_len == 0) {
        return 0;
    }

    char visited[s_len];
    int longest_length = 1;
    int current_length = 0;
    int i = 0;
    int j = 0;

    for (i = 0; i < s_len; i++) {
        empty_visited_array(visited, s_len);
        visited[0] = s[i];
        current_length = 1;

        for (j = i + 1; j < s_len; j++) {
            if (was_visited(s[j], visited, current_length)) {
                break;
            }

            visited[current_length] = s[j];
            current_length++;
            longest_length = max(current_length, longest_length);
        }

        if (longest_length == s_len) {
            break;
        }
    }


    return longest_length;
}

int main(int argc, char const *argv[]) {
    const char *test1 = "abcabcbb";
    const char *test2 = "bbbbb";
    const char *test3 = "pwwkew";
    const char *test4 = "au";
    int result = -1;

    result = lengthOfLongestSubstring(test1);
    printf("%d\n", result);
    
    result = lengthOfLongestSubstring(test2);
    printf("%d\n", result);
    
    result = lengthOfLongestSubstring(test3);
    printf("%d\n", result);
    
    result = lengthOfLongestSubstring(test4);
    printf("%d\n", result);

    return 0;
}
