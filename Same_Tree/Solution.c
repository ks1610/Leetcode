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

    // Creating first tree
    struct TreeNode* tree_3 = new_TreeNode(1);
    tree_3->left = new_TreeNode(0);
    tree_3->right = new_TreeNode(3);
    
    // Creating second tree
    struct TreeNode* tree_4 = new_TreeNode(1);
    tree_4->left = new_TreeNode(2);
    tree_4->right = new_TreeNode(3);
    
    (isSameTree(tree_1, tree_2))? printf("same\n") : printf("not same\n");
    (isSameTree(tree_3, tree_4))? printf("same\n") : printf("not same\n");

    // Free the allocated memory
    free(tree_1->left);
    free(tree_1->right);
    free(tree_1);
    free(tree_2->left);
    free(tree_2->right);
    free(tree_2);
    free(tree_3->left);
    free(tree_3->right);
    free(tree_3);
    free(tree_4->left);
    free(tree_4->right);
    free(tree_4);

    return 0;
}
