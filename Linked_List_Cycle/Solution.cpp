#include <bits/stdc++.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* new_node(ListNode*head, int x){
        head->val = x;
        head->next = NULL;
        return head;
    }
    bool hasCycle(ListNode *head) {
        if(head == NULL || head-> next == NULL)
            return false;
        
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast != NULL && fast-> next != NULL){
            fast = fast->next->next;
            slow = slow-> next;

            if(fast == slow)
                return true;
        }
        return false;
    }
    // Function to get the size of the linked list
    int printList(ListNode* head) {
        ListNode* current = head;

        while (current->next != nullptr) {
            std::cout << current->val << " ";
            current = current->next;
        }
        return current->val;
    }
    ListNode* insert_node(ListNode* head, int value){
        ListNode* newNode = new ListNode(value); 
        if(head == NULL)
            return newNode; 
        else{        
            ListNode* temp = head;
            while(temp->next){
                temp = temp->next;
            }   

            temp->next = newNode;
            return head;
        }
    }
};
int main() {
    Solution s;
    ListNode* head = NULL;
    
    head = s.insert_node(head, 1);
    head = s.insert_node(head, 2);
    head = s.insert_node(head, 0);
    head = s.insert_node(head, 4);

    std::cout << "List: ";
    s.printList(head);  // Now just prints the list

    std::cout << "Is Circle? ";
    if(s.hasCycle(head)) {
        std::cout << "true" << std::endl;
    } else {
        std::cout << "false" << std::endl;
    }

    return 0;
}
