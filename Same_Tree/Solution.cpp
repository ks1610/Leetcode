#include <bits/stdc++.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL)
            return true;
        else if(p == NULL || q == NULL || p->val != q->val)
            return false;
        else
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

int main(){
    //case same tree
    TreeNode* tree_1 = new TreeNode(1);
    tree_1 ->left = new TreeNode(2);
    tree_1 ->right = new TreeNode(3);

    TreeNode* tree_2 = new TreeNode(1);
    tree_2 ->left = new TreeNode(2);
    tree_2 ->right = new TreeNode(3);


    //case not same tree
    TreeNode* tree_3 = new TreeNode(1);
    tree_3 ->left = new TreeNode(0);
    tree_3 ->right = new TreeNode(2);

    TreeNode* tree_4 = new TreeNode(1);
    tree_4 ->left = new TreeNode(2);
    
    Solution solution;
    int result = solution.isSameTree(tree_1, tree_2);
    (result == 1) ? std::cout << "same\n" : std::cout << "not same\n";
    
    result = solution.isSameTree(tree_3, tree_4);
    (result == 1) ? std::cout << "same\n" : std::cout << "not same\n";

    // Cleanup memory (optional but good practice)
    delete tree_1->left;
    delete tree_1->right;
    delete tree_1;
    delete tree_2->left;
    delete tree_2->right;
    delete tree_2;

    return 0;
}
