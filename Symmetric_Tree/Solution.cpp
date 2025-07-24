#include <iostream>

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
    bool isSymmetric(TreeNode* root) {
        return isVail(root->left, root->right);
    }
    bool isVail(TreeNode* node_1, TreeNode* node_2){
        if(node_1 == NULL && node_2 == NULL)
            return true;
        
        if(node_1 == NULL || node_2 == NULL)
            return false;
        
        return node_1->val == node_2->val && isVail(node_1->left, node_2->right) && isVail(node_1->right, node_2->left);
    }
};


int main(){
    TreeNode* node = new TreeNode(1);
    node->left = new TreeNode(2);
    node->right = new TreeNode(2);
    node->left->right = new TreeNode(3);
    node->left->left = new TreeNode(4); 
    node->right->left = new TreeNode(3);
    node->right->right = new TreeNode(4);
    Solution check;
    
    std::cout<< (check.isSymmetric(node)?"Symmetric Tree" : "Not A Symmetric Tree");   
    
    delete node->right->right;
    delete node->right->left;
    delete node->right;
    delete node->left;
    delete node;
}
