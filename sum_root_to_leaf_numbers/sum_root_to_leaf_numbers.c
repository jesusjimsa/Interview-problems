/**
    You are given the `root` of a binary tree containing digits from `0` to `9` only.

    Each root-to-leaf path in the tree represents a number.

    * For example, the root-to-leaf path `1 -> 2 -> 3` represents the number `123`.

    Return the total sum of all root-to-leaf numbers. Test cases are generated so that the answer will fit in a 32-bit integer.

    A leaf node is a node with no children.

    ### Example 1:

    ```
    Input: root = [1,2,3]
    Output: 25
    Explanation:
    The root-to-leaf path 1->2 represents the number 12.
    The root-to-leaf path 1->3 represents the number 13.
    Therefore, sum = 12 + 13 = 25.
    ```

    ### Example 2:

    ```
    Input: root = [4,9,0,5,1]
    Output: 1026
    Explanation:
    The root-to-leaf path 4->9->5 represents the number 495.
    The root-to-leaf path 4->9->1 represents the number 491.
    The root-to-leaf path 4->0 represents the number 40.
    Therefore, sum = 495 + 491 + 40 = 1026.
    ```

    ## Constraints:

    * The number of nodes in the tree is in the range `[1, 1000]`.
    * `0 <= Node.val <= 9`
    * The depth of the tree will not exceed `10`.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int travel(struct TreeNode* root, int previous) {
    int sum = (previous * 10) + root->val;
    int sum_l = 0;
    int sum_r = 0;

    if (root->left != NULL || root->right != NULL) {
        if (root->left) {
            sum_l = travel(root->left, sum);
        }

        if (root->right) {
            sum_r = travel(root->right, sum);
        }

        sum = sum_r + sum_l;
    }

    return sum;
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int sumNumbers(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    return travel(root, 0);
}

int main(int argc, char const *argv[]) {
    struct TreeNode *tree = malloc(sizeof(struct TreeNode));

    tree->val = 4;
    tree->left = malloc(sizeof(struct TreeNode));
    tree->left->val = 0;
    tree->right = malloc(sizeof(struct TreeNode));
    tree->right->val = 9;
    tree->right->right = malloc(sizeof(struct TreeNode));
    tree->right->right->val = 5;
    tree->right->left = malloc(sizeof(struct TreeNode));
    tree->right->left->val = 1;

    printf("%d\n", sumNumbers(tree));

    if (tree->right->left) {
        free(tree->right->left);
        tree->right->left = NULL;
    }

    if (tree->right->right) {
        free(tree->right->right);
        tree->right->right = NULL;
    }

    tree->val = 1;
    tree->left->val = 2;
    tree->right->val = 3;

    printf("%d\n", sumNumbers(tree));

    if (tree->right) {
        free(tree->right);
        tree->right = NULL;
    }

    if (tree->left) {
        free(tree->left);
        tree->left = NULL;
    }

    if (tree) {
        free(tree);
        tree = NULL;
    }

    return 0;
}

