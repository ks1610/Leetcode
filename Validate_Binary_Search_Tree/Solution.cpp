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
    bool Possible(TreeNode* Node, long long min, long long max){
        if(!Node)
            return true;
        if(!(Node->val > min && Node->val <max))
            return false;
        return Possible(Node->left, min, Node->val) && Possible(Node->right, Node->val, max); 
    }
    bool isValidBST(TreeNode* root) {
        long long min_val = -1000000000000000000;
        long long max_val = 100000000000000000;
        return Possible(root, min_val, max_val);
    }
};

int main(){
    TreeNode* node = new TreeNode(5);
    node->left = new TreeNode(1);
    node->right = new TreeNode(4);
    node->right->left = new TreeNode(3);
    node->right->right = new TreeNode(6);
    Solution check;
    
    std::cout<< (check.isValidBST(node)?"Vail Tree" : "Invail Tree");   
    
    delete node->right->right;
    delete node->right->left;
    delete node->right;
    delete node->left;
    delete node;
}
