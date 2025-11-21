#include <iostream>
#include <climits>
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

// Recursive search
Node* searchRec(Node *root, int key) {
    if (root == NULL || root->key == key) return root;
    if (key < root->key) return searchRec(root->left, key);
    else return searchRec(root->right, key);
}

// Iterative search
Node* searchIter(Node *root, int key) {
    Node *curr = root;
    while (curr != NULL) {
        if (key == curr->key) return curr;
        else if (key < curr->key) curr = curr->left;
        else curr = curr->right;
    }
    return NULL;
}

Node* findMinNode(Node *root) {
    if (root == NULL) return NULL;
    while (root->left != NULL)
        root = root->left;
    return root;
}

Node* findMaxNode(Node *root) {
    if (root == NULL) return NULL;
    while (root->right != NULL)
        root = root->right;
    return root;
}

int minElement(Node *root) {
    Node *t = findMinNode(root);
    if (t == NULL) return INT_MIN;
    return t->key;
}

int maxElement(Node *root) {
    Node *t = findMaxNode(root);
    if (t == NULL) return INT_MAX;
    return t->key;
}

// Inorder successor (by key)
Node* inorderSuccessor(Node *root, int key) {
    Node *succ = NULL;
    Node *curr = root;
    while (curr != NULL) {
        if (key < curr->key) {
            succ = curr;
            curr = curr->left;
        } else if (key > curr->key) {
            curr = curr->right;
        } else {
            if (curr->right != NULL) {
                Node *t = curr->right;
                while (t->left != NULL) t = t->left;
                succ = t;
            }
            break;
        }
    }
    return succ;
}

// Inorder predecessor (by key)
Node* inorderPredecessor(Node *root, int key) {
    Node *pred = NULL;
    Node *curr = root;
    while (curr != NULL) {
        if (key > curr->key) {
            pred = curr;
            curr = curr->right;
        } else if (key < curr->key) {
            curr = curr->left;
        } else {
            if (curr->left != NULL) {
                Node *t = curr->left;
                while (t->right != NULL) t = t->right;
                pred = t;
            }
            break;
        }
    }
    return pred;
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

    int key = 40;
    cout << "Search Recursive " << key << ": "
         << (searchRec(root, key) ? "Found" : "Not Found") << endl;

    cout << "Search Iterative " << key << ": "
         << (searchIter(root, key) ? "Found" : "Not Found") << endl;

    cout << "Min element: " << minElement(root) << endl;
    cout << "Max element: " << maxElement(root) << endl;

    Node *succ = inorderSuccessor(root, 50);
    if (succ) cout << "Inorder successor of 50: " << succ->key << endl;
    else cout << "No successor\n";

    Node *pred = inorderPredecessor(root, 50);
    if (pred) cout << "Inorder predecessor of 50: " << pred->key << endl;
    else cout << "No predecessor\n";

    return 0;
}
