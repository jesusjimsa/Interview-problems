/*
    How would you design design a stack which, in adition to `push` and `pop`, has a function `min` which returns the
    minimum element? `Push`, `pop` and `min` should all operate in O(1) time.
*/

#include <iostream>
#include <limits.h>

using namespace std;

struct MyStackNode {
    int data;
    MyStackNode *next;
    int min_so_far = INT_MAX;
};

class MyStackMin {
    private:
        MyStackNode *top;
    public:
        int pop() {
            int item = top->data;

            top = top->next;

            // When doing the pop operation, the minimum value will be up to date because we save the min so far value 
            // every time
            return item;
        }

        void push(int item) {
            MyStackNode *t;

            // Save the minimun value so far in the stack in the top
            t->min_so_far = item < top->min_so_far ? item : top->min_so_far;

            t->data = item;
            t->next = top;
            top = t;
        }

        int min() {
            return top->min_so_far;
        }
};

int main () {
    MyStackMin test;

    test.push(12);
    test.push(2);
    test.push(5);
    test.push(-4);

    cout << test.min() << endl;

    test.pop();

    cout << test.min() << endl;
}
