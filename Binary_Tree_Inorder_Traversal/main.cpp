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
        std::vector<int> inorderTraversal(TreeNode* root) {
            std::vector<int> newVal;
            //TreeNode* curr = root;
            //newVal.push_back(curr->val);
    
            if(root == NULL)
                return newVal;
            std::vector<int> left = inorderTraversal(root->left);
            newVal.insert(newVal.end(), left.begin(), left.end());
            newVal.push_back(root->val);
            std::vector<int> right = inorderTraversal(root->right);
            newVal.insert(newVal.end(), right.begin(), right.end());
            return newVal;
        }
        /*
        TreeNode* insertTree(TreeNode* root, int newVal){
            if(root == NULL)
                return new TreeNode(newVal);
            if(newVal > root->val)
                root->right = insertTree(root->right, newVal);
            else 
                root->left = insertTree(root->left, newVal);
            return root;
        }
        */
};

int main()
{
    //TreeNode* node = NULL;
    Solution* s;
    /*std::vector<int> Tree = {1,2,3,4,5,8,6,7,9};
    for(int val : Tree){
        node = s->insertTree(node, val);
    }*/
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    std::vector<int> inorder = s->inorderTraversal(root);

    for(int out : inorder){
        std::cout<< out <<" ";
    }
    std::cout<<std::endl;
    
    return 0;
}
