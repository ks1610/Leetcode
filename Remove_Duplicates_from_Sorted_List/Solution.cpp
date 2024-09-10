#include <bits/stdc++.h>

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // empty list
        if (head == NULL) {
            return head;
        }
        // non-empty list
        ListNode* curr = head;

        while(curr != NULL && curr->next != NULL){
            if(curr->val == curr->next->val){
                ListNode* next = curr->next->next;
                delete(curr->next);
                curr->next = next;
            }
            else
                curr = curr->next;
        }
        return head;
    }
};

int main(){
    // Create the linked list: 1 -> 1 -> 2 -> 3 -> 3
    ListNode* head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(3);

    // Create the solution object
    Solution solution;

    // Delete duplicates   
    ListNode* result = solution.deleteDuplicates(head);

   // Print the result
    ListNode* curr = result;
    while(result != NULL){
        std::cout<< curr->val<<" ";
        curr = curr->next;
    } 

    // Free the allocated memory
    while (result != nullptr) {
        ListNode* temp = result;
        result = result->next;
        delete temp;
    }
}
