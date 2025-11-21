#include <iostream>
#include <climits>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

bool isBSTUtil(Node *root, long long minVal, long long maxVal) {
    if (root == NULL) return true;
    if (root->data <= minVal || root->data >= maxVal) return false;
    return isBSTUtil(root->left, minVal, root->data) &&
           isBSTUtil(root->right, root->data, maxVal);
}

bool isBST(Node *root) {
    return isBSTUtil(root, LLONG_MIN, LLONG_MAX);
}

int main() {
    // Tree 1: BST
    Node *root1 = new Node(4);
    root1->left = new Node(2);
    root1->right = new Node(6);
    root1->left->left = new Node(1);
    root1->left->right = new Node(3);

    // Tree 2: not BST
    Node *root2 = new Node(5);
    root2->left = new Node(2);
    root2->right = new Node(8);
    root2->left->right = new Node(7); // violates

    cout << "Tree 1 is " << (isBST(root1) ? "BST" : "Not BST") << endl;
    cout << "Tree 2 is " << (isBST(root2) ? "BST" : "Not BST") << endl;

    return 0;
}
