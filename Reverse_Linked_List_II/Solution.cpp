#include <bits/stdc++.h>
#include <string>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || left == right){
            return head;
        }
        
        ListNode* dump = new ListNode(0);
        dump->next = head;
        ListNode* prev = dump;

        for(int i = 0; i < left - 1; i++){
            prev = prev->next;
        }

        ListNode* curr = prev->next;

        for(int i = 0; i < right - left; i++){
            ListNode* temp = curr->next;
            curr->next = temp->next;
            temp->next = prev->next;
            prev->next = temp;
        }

        return dump->next;
    }
    void print_list(ListNode* head){
        ListNode* temp = head;
        while(temp != NULL){
            std::cout<<temp->val<<" ";
            temp = temp->next;
        }
        std::cout<<std::endl;
    }
};

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution solution;
    solution.reverseBetween(head, 2, 4);
    solution.print_list(head);
    
    
    ListNode* head_1 = new ListNode(5);
    
    solution.reverseBetween(head_1, 1, 1);
    solution.print_list(head_1);
}
