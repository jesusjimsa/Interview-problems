/*
    How would you design design a stack which, in adition to `push` and `pop`, has a function `min` which returns the
    minimum element? `Push`, `pop` and `min` should all operate in O(1) time.
*/

#include <iostream>
#include <limits.h>

using namespace std;

class StackNode {
public:
    int data;
    StackNode* next;
    int min_so_far;

    StackNode() {
        min_so_far = INT_MAX;
    }
};

class MyStackMin {
    private:
        StackNode* root;
    public:
        MyStackMin() {
            root = new StackNode();
        }

        int isEmpty() {
            return !root;
        }

        void push(int data) {
            StackNode* stackNode = new StackNode();

            stackNode->min_so_far = data < root->min_so_far ? data : root->min_so_far;

            stackNode->data = data;
            stackNode->next = NULL;
            stackNode->next = root;
            root = stackNode;
        }

        int pop() {
            if (isEmpty()) {
                return INT_MIN;
            }

            StackNode* temp = root;
            int popped = temp->data;

            root = root->next;

            free(temp);

            return popped;
        }

        int min() {
            return root->min_so_far;
        }
};

int main() {
    MyStackMin test;

    test.push(12);
    test.push(2);
    test.push(5);
    test.push(-4);

    cout << test.min() << endl;

    test.pop();

    cout << test.min() << endl;
}
