/*
    Write a method that takes a pointer to a `Node` structure as a parameter and returns a complete copy of the passed
    in data structure. The `Node` data structure contains two pointers to other `Nodes`.
*/

#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }

    ~Node() {
        delete left;
        delete right;
    }

    Node* copy_node() {
        if (!this) {
            return nullptr;
        }

        Node* new_node = new Node(this->data);

        new_node->left = this->left ? this->left->copy_node() : nullptr;
        new_node->right = this->right ? this->right->copy_node() : nullptr;

        return new_node;
    }
};

void printTree(const Node* root) {
    if (root) {
        printTree(root->left);
        cout << root->data << " ";
        printTree(root->right);
    }
}

int main(int argc, char const *argv[]) {
    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Original tree: ";
    printTree(root);
    cout << endl;

    Node* copy = root->copy_node();

    delete root;

    cout << "Copied tree: ";
    printTree(copy);
    cout << endl;

    delete copy;

    return 0;
}
