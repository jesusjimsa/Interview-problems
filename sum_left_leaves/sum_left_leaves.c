/*
    Given the `root` of a binary tree, return the sum of all left leaves.

    A leaf is a node with no children. A left leaf is a leaf that is the left child of another node.

    ### Example 1:
    ```
    Input: root = [3, 9, 20, null, null, 15, 7]
    Output: 24
    Explanation: There are two left leaves in the binary tree, with values 9 and 15 respectively.
    ```

    ### Example 2:
    ```
    Input: root = [1]
    Output: 0
    ```

    Constraints:

    * The number of nodes in the tree is in the range `[1, 1000]`.
    * `-1000 <= Node.val <= 1000`
*/

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int sumOfLeftLeaves(struct TreeNode* root) {
    int result = 0;

    if (root->left) {
        // It doesn't have children, therefore it's a leaf
        if (root->left->left == NULL && root->left->right == NULL) {
            result += root->left->val;
        }

        result += sumOfLeftLeaves(root->left);
    }

    if (root->right) {
        result += sumOfLeftLeaves(root->right);
    }

    return result;
}

int main(int argc, char const *argv[]) {
    struct TreeNode *tree = malloc(sizeof(struct TreeNode));

    tree->val = 3;
    tree->left = malloc(sizeof(struct TreeNode));
    tree->left->val = 9;
    tree->right = malloc(sizeof(struct TreeNode));
    tree->right->val = 20;
    tree->right->right = malloc(sizeof(struct TreeNode));
    tree->right->right->val = 7;
    tree->right->left = malloc(sizeof(struct TreeNode));
    tree->right->left->val = 15;

    printf("%d\n", sumOfLeftLeaves(tree));

    if (tree->right->left) {
        free(tree->right->left);
        tree->right->left = NULL;
    }

    if (tree->right->right) {
        free(tree->right->right);
        tree->right->right = NULL;
    }

    if (tree->right) {
        free(tree->right);
        tree->right = NULL;
    }

    if (tree->left) {
        free(tree->left);
        tree->left = NULL;
    }

    tree->val = 1;

    printf("%d\n", sumOfLeftLeaves(tree));

    return 0;
}

