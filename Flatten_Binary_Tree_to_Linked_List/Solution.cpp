#include <iostream>
#include <vector>

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
    void pre_order(TreeNode* node, std::vector<TreeNode*>& res) {
        if (!node)
            return;
        res.push_back(node);
        pre_order(node->left, res);
        pre_order(node->right, res);
    }

    void flatten(TreeNode* root) {
        if (!root)
            return;
        std::vector<TreeNode*> res;
        pre_order(root, res);
        for (int i = 0; i < res.size() - 1; i++) {
            res[i]->left = nullptr;
            res[i]->right = res[i + 1];
        }
    }
};

void printFlattened(TreeNode* root) {
    TreeNode* curr = root;
    while (curr) {
        std::cout << curr->val << " ";
        curr = curr->right;
    }
    std::cout << std::endl;
}

int main() {

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2, new TreeNode(3), new TreeNode(4));
    root->right = new TreeNode(5, nullptr, new TreeNode(6));

    Solution sol;
    sol.flatten(root);

    std::cout << "Flattened tree (preorder as right-linked list): ";
    printFlattened(root);

    return 0;
}
