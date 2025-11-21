#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int key;
    Node *left, *right;
    Node(int x) {
        key = x;
        left = right = NULL;
    }
};

Node* insert(Node *root, int key) {
    if (root == NULL) return new Node(key);
    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    return root;
}

Node* findMinNode(Node *root) {
    while (root && root->left) root = root->left;
    return root;
}

Node* deleteNode(Node *root, int key) {
    if (root == NULL) return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            Node *t = root->right;
            delete root;
            return t;
        } else if (root->right == NULL) {
            Node *t = root->left;
            delete root;
            return t;
        }
        Node *t = findMinNode(root->right);
        root->key = t->key;
        root->right = deleteNode(root->right, t->key);
    }
    return root;
}

int maxDepth(Node *root) {
    if (root == NULL) return 0;
    int l = maxDepth(root->left);
    int r = maxDepth(root->right);
    return max(l, r) + 1;
}

int minDepth(Node *root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    if (root->left == NULL) return 1 + minDepth(root->right);
    if (root->right == NULL) return 1 + minDepth(root->left);
    return 1 + min(minDepth(root->left), minDepth(root->right));
}

void inorder(Node *root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
}

int main() {
    Node *root = NULL;
    int arr[] = {50, 30, 70, 20, 40, 60, 80};
    int n = 7;

    for (int i = 0; i < n; i++)
        root = insert(root, arr[i]);

    cout << "Inorder: ";
    inorder(root);
    cout << endl;

    cout << "Max depth: " << maxDepth(root) << endl;
    cout << "Min depth: " << minDepth(root) << endl;

    root = deleteNode(root, 70);
    cout << "After deleting 70, inorder: ";
    inorder(root);
    cout << endl;

    return 0;
}
