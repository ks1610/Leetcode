#include <bits/stdc++.h>

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr)
            return 0;
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return 1 + (left > right ? left : right);
    }
};

int main() {
    // Build a tree:
    //        1
    //       / \
    //      2   3
    //     / \
    //    4   5
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right = new TreeNode(3);

    Solution sol;
    cout << "Max Depth: " << sol.maxDepth(root) << endl;  // Expected 3

    return 0;
}
