#include <iostream>
#include <unordered_set>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) {
        data = val;
        left = right = NULL;
    }
};

// Helper function: DFS traversal + check duplicates
bool checkDuplicates(TreeNode* root, unordered_set<int> &seen) {
    if (root == NULL) return false;

    // if current value already seen, duplicate exists
    if (seen.find(root->data) != seen.end()) {
        return true;
    }
    seen.insert(root->data);

    // check in left and right subtrees
    bool leftDup = checkDuplicates(root->left, seen);
    if (leftDup) return true;

    bool rightDup = checkDuplicates(root->right, seen);
    return rightDup;
}

bool hasDuplicateValues(TreeNode* root) {
    unordered_set<int> seen;
    return checkDuplicates(root, seen);
}

int main() {
    /*
            5
           / \
          3   7
         / \   \
        2   3   9

        Here value 3 is duplicate
    */

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(3); // duplicate value
    root->right->right = new TreeNode(9);

    if (hasDuplicateValues(root))
        cout << "Duplicates Found\n";
    else
        cout << "No Duplicates\n";

    return 0;
}
