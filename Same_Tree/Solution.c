#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;

};

struct TreeNode* new_TreeNode(int new_val){
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = new_val;
    node->left = NULL;
    node->right = NULL;
}

int isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if(p == NULL && q == NULL)
        return 1;
    else if(p == NULL || q == NULL || p->val != q->val)
        return 0;
    else
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main(){
    // Creating first tree
    struct TreeNode* tree_1 = new_TreeNode(1);
    tree_1->left = new_TreeNode(2);
    tree_1->right = new_TreeNode(3);
    
    // Creating second tree
    struct TreeNode* tree_2 = new_TreeNode(1);
    tree_2->left = new_TreeNode(2);
    tree_2->right = new_TreeNode(3);
    (isSameTree(tree_1, tree_2))? printf("same") : printf("not same");

    // Free the allocated memory
    free(tree_1->left);
    free(tree_1->right);
    free(tree_1);
    free(tree_2->left);
    free(tree_2->right);
    free(tree_2);

    return 0;
}
