#include <bits/stdc++.h>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       if(root == NULL){
            return NULL;
       }
       int cur = root->val;
       if(cur == p->val || cur == q->val){
            return root;
       }
       if(cur < p->val && cur < q->val){
            return lowestCommonAncestor(root->right, p, q);
       }
       if(cur > p->val && cur > q->val){
            return lowestCommonAncestor(root->left, p, q);
       }
       return root;
    }
};

int main() {
    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);

    Solution s;

    TreeNode* p = root->left;          
    TreeNode* q = root->left->right;   

    TreeNode* ans = s.lowestCommonAncestor(root, p, q);

    std::cout << "Lowest Common Ancestor of " 
         << p->val << " and " << q->val 
         << " = " << ans->val << std::endl;

    return 0;
}
