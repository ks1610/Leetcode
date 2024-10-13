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
    std::vector<int> preorderTraversal(TreeNode* root) {
        std::vector<int> res;
        
        preorder(root, res);
        
        return res;
    }

private:
    void preorder(TreeNode* node, std::vector<int>& res){
        if(node == NULL)
            return;
        
        res.push_back(node->val);
        preorder(node->left, res);
        preorder(node->right, res);
    }
};

void print_list(TreeNode* node) {
    if (node == NULL)
        return;
    
    // Traverse the left subtree
    print_list(node->left);
    
    // Print the value of the current node
    std::cout << node->val << " ";
    
    // Traverse the right subtree
    print_list(node->right);
}

int main() {
    // Creating a simple binary tree
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    
    // Print the tree nodes in in-order traversal
    std::cout << "In-order traversal: ";
    print_list(root);
    std::cout << std::endl;
    
    // Use the Solution class to get the pre-order traversal
    Solution solution;
    std::vector<int> preorder_result = solution.preorderTraversal(root);
    
    // Print pre-order traversal
    std::cout << "Pre-order traversal: ";
    for (int val : preorder_result) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // Clean up the allocated memory
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
