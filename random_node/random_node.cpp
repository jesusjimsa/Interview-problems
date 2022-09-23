/*
    You are implementing a binary search tree class which, in addition to `insert`, `find` and `delete`, has a method
    `getRandomNode()` which returns a random node from the tree. All nodes should be equally likely to be chosen.

    Design and implement an algorithm foor `getRandomNode()`, and explain how you would implement the rest of the
    methods.
*/

#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;

struct BSTNode {
    int data;
    struct BSTNode *left;
    struct BSTNode *right;
};

class BST {
    private:
        int data;
        struct BST *left;
        struct BST *right;

        BST* continueRandomNode(BST* root, int num_steps) {
            int rand_lr = rand() % 1;

            if ((root->right == NULL && root->left == NULL) || num_steps == 0) {
                return root;
            }

            if (root->left != NULL && root->right != NULL) {
                int rand_lr = rand() % 1;

                if (rand_lr == 0) {
                    return continueRandomNode(root->left, num_steps - 1);
                }
                else {
                    return continueRandomNode(root->right, num_steps - 1);
                }
            }
            else if (root->left != NULL) {
                return continueRandomNode(root->left, num_steps - 1);
            }
            else if (root->right != NULL) {
                return continueRandomNode(root->right, num_steps - 1);
            }

            return root;
        }
    public:
        BST(int value) {
            data = value;
            left = NULL;
            right = NULL;
        }

        BST* Insert(BST* root, int data) {
            if (!root) {
                return new BST(data);
            }

            if (data >= root->data) {
                root->right = Insert(root->right, data);
            }
            else {
                root->left = Insert(root->left, data);
            }

            return root;
        }

        BST* Find(BST* root, int data) {
            if (!root || root->data == data)  {
                return root;
            }

            if (data > root->data) {
                return Find(root->right, data);
            }

            return Find(root->left, data);
        }

        BST* Delete(BST* root, int data) {
            if (root == NULL) {
                return root;
            }

            if (data > root->data) {
                root->right = Delete(root->right, data);
            }
            else if (data < root->data) {
                root->left = Delete(root->left, data);
            }
            else {
                if (root->right == NULL && root->left == NULL) {
                    return NULL;
                }

                if (root->left == NULL) {
                    BST* temp = root->right;
                    free(root);
                    return temp;
                }
                else if (root->right == NULL) {
                    BST* temp = root->left;
                    free(root);
                    return temp;
                }

                BST* temp = root->right;
                root->data = temp->data;
                root->right = Delete(root->right, temp->data);
            }

            return root;
        }


        BST* getRandomNode(BST* root) {
            int rand_steps = rand() % 256 + 1;

            if (!root) {
                return root;
            }

            return continueRandomNode(root, rand_steps);
        }

        int getData() {
            return data;
        }
};

int main() {
    srand (time(NULL));

    BST* root = new BST(2);

    for (int i = 0; i < 30; i++) {
        root->Insert(root, rand() % 256 + 1);
    }

    cout << root->getRandomNode(root)->getData() << endl;
}
