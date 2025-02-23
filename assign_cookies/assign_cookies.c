/*
    Assume you are an awesome parent and want to give your children some cookies. But, you should give each child at
    most one cookie.

    Each child `i` has a greed factor `g[i]`, which is the minimum size of a cookie that the child will be content with;
    and each cookie `j` has a size `s[j]`. If `s[j] >= g[i]`, we can assign the cookie `j` to the child `i`, and the
    child `i` will be content. Your goal is to maximize the number of your content children and output the maximum
    number.

    ## Example 1:
    ```
    Input: g = [1,2,3], s = [1,1]
    Output: 1
    Explanation: You have 3 children and 2 cookies. The greed factors of 3 children are 1, 2, 3.
    And even though you have 2 cookies, since their size is both 1, you could only make the child whose greed factor is
    1 content.
    You need to output 1.
    ```

    ## Example 2:
    ```
    Input: g = [1,2], s = [1,2,3]
    Output: 2
    Explanation: You have 2 children and 3 cookies. The greed factors of 2 children are 1, 2.
    You have 3 cookies and their sizes are big enough to gratify all of the children,
    You need to output 2.
    ```

    ## Constraints:

    * `1 <= g.length <= 3 * 10^4`
    * `0 <= s.length <= 3 * 10^4`
    * `1 <= g[i], s[j] <= 2^31 - 1`
*/

#include <stdio.h>
#include <stdlib.h>

// Descending order
int comp(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

int findContentChildren(int* g, int gSize, int* s, int sSize) {
    int cookies_given = 0;
    int next_available_cookie = 0;
    int i = 0;
    int j = 0;

    if (gSize == 0 || sSize == 0) {
        return 0;
    }

    qsort(g, gSize, sizeof(g[0]), comp);
    qsort(s, sSize, sizeof(s[0]), comp);

    for (i = 0; i < gSize; i++) {
        if (s[next_available_cookie] >= g[i]) {
            cookies_given++;

            if (next_available_cookie + 1 < sSize) {
                next_available_cookie++;
            }
            else {
                break;  // No more cookies left :(
            }
        }
    }

    return cookies_given;
}

int main(int argc, char const *argv[]) {
    int greed[] = {1, 2, 3};
    int cookies[] = {1, 1};

    printf("Cookies given: %d\n", findContentChildren(&greed, 3, &cookies, 2));
    
    int greed2[] = {1, 2};
    int cookies2[] = {1, 2, 3};

    printf("Cookies given: %d\n", findContentChildren(&greed2, 2, &cookies2, 3));

    return 0;
}
