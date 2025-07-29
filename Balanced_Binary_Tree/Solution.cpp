#include <bits/stdc++.h>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    int sideHeight(TreeNode* node){
        if(!node)
            return 0;
        int rightHeight = sideHeight(node->right);
        if(rightHeight == -1) return -1;
        int leftHeight = sideHeight(node->left);
        if(leftHeight == -1) return -1;
        return 1 + std::max(leftHeight, rightHeight);
    }
    bool isBalanced(TreeNode* root) {
        if(!root)
            return true;
        int rightHeight = sideHeight(root->right);
        int leftHeight = sideHeight(root->left);
        if (std::abs((int)(leftHeight - rightHeight)) > 1)
            return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
};

int main(){
    // Balanced tree:   
    TreeNode* root = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    Solution s;
    bool result = s.isBalanced(root);  // true
}
