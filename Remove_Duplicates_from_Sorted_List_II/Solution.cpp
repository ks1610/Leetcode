#include <bits/stdc++.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        if (!head) return NULL;  // Handle empty list
        
        ListNode* dummy = new ListNode(0);
        dummy->next= head;
        ListNode* current = head;
        ListNode* pre = dummy;
        
        while(current != NULL){
            bool isduplicted = false;

            while(current->next != NULL && current->val == current->next->val){
                isduplicted = true;
                ListNode* temp = current -> next;   // Save the node to delete
                current->next = current->next->next;  // Skip the duplicate
                delete temp;  // Free memory  
            }
            if(isduplicted)
            {
                pre->next = current->next;
                delete current;
            }
            else 
                pre = current;   
            current = pre->next;
        }

        ListNode* newhead = dummy->next;
        delete dummy;
        return newhead;
    }
    ListNode*insert_node(ListNode* head, int new_val){
        
        ListNode* newnode = new ListNode(new_val);

        if(head == NULL)
            return newnode;
        else{
            ListNode* temp = head;
            while(temp->next){
                temp = temp->next;
            }

            temp->next = newnode;
            return head;
        }
    }

    void printlist(ListNode* head){
        ListNode* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
            std::cout << temp->next <<" ";
        } 
    }
};
int main() {
    Solution s;
    ListNode* head = NULL;
    
    head = s.insert_node(head, 3);
    head = s.insert_node(head, 1);
    head = s.insert_node(head, 2);
    head = s.insert_node(head, 2);
    
    s.deleteDuplicates(head);
    
    ListNode* temp = head;
    std::cout<<temp->val<<" ";
    while(temp->next != NULL){
        temp = temp->next;
        std::cout << temp->val <<" ";
    } 

    return 0;
}
