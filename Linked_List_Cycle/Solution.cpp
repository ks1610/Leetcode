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
    // Function to insert a new node at the end of the linked list
    ListNode* insert_node(ListNode* head, int value) {
        ListNode* newNode = new ListNode(value); 
        if(head == NULL)
            return newNode; 
        else {        
            ListNode* temp = head;
            while(temp->next) {
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
    
    head = s.insert_node(head, 3);
    head = s.insert_node(head, 2);
    head = s.insert_node(head, 0);
    head = s.insert_node(head, -4);
    
    // Manually creating a cycle: pointing the last node (4) back to the second node (2)
    ListNode* temp = head;
    std::cout<<"List: ";
    while(temp->next != NULL) {
        std::cout << temp->val << " ";
        temp = temp->next;
    }
    temp->next = head->next;  // Creates a cycle by pointing the last node to the second node
    std::cout<<temp->val<<std::endl;

    //std::cout << "List: ";
    //s.printList(head);  // Now just prints the list

    std::cout << "Is Circle? ";
    if(s.hasCycle(head)) {
        std::cout << "true" << std::endl;
    } else {
        std::cout << "false" << std::endl;
    }

    return 0;
}
