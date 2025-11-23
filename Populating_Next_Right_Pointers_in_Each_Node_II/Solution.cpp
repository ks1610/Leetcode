#include <bits/stdc++.h>


class Node{
public:
    int val;
    Node* left;
    Node* right;
    Node* next;
    
    Node(int _val) {
        val = _val;
        left = right = next = NULL;
    }

};

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL)
            return root;
        std::queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            int n = q.size();
            for(int i = 0; i < n; i++){
                Node* head = q.front();
                q.pop();
                if(i < n-1)
                    head->next = q.front();
                if(head->left)
                    q.push(head->left);
                if(head->right)
                    q.push(head->right); 
            }
        }
        return root;
    }

   void printroot(Node* root) {
        Node* level = root;

        while (level != NULL) {
            Node* curr = level;

            while (curr != NULL) {
                std::cout << curr->val << ",";
                curr = curr->next;
            }

            std::cout << "#,";

            if (level->left)
                level = level->left;
            else if (level->right)
                level = level->right;
            else
                level = NULL;
        }
    }

};

int main() {
    Node* head = new Node(1);
    head->left = new Node(2);
    head->right = new Node(3);
    head->left->left = new Node(4);
    head->left->right = new Node(5);
    head->right->right = new Node(7);

    Solution s;
    s.connect(head);
    s.printroot(head);

    return 0;
}
