#include<bits/stdc++.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* new_node(ListNode*head, int x){
        head->val = x;
        head->next = NULL;
        return head;
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k == 0)
            return head;

        int length = 1;
        ListNode* last = head;
        while(last->next != NULL)
        {
            last = last->next;
            length++;
        }

        k = k % length;
        if(k==0)
            return head;

        int newLastIndex = length - k - 1;
        ListNode* newLast = head;
        for (int i = 0; i < newLastIndex; ++i) {
            newLast = newLast->next;
        }

        ListNode* newHead = newLast->next;
        newLast->next = NULL;
        last->next = head;

        return newHead;
    }
};

int main(){
    Solution new_solution;
    ListNode* head = NULL;
    head = new_solution.insert_node(head, 1);
    head = new_solution.insert_node(head, 2);
    head = new_solution.insert_node(head, 3);
    head = new_solution.insert_node(head, 4);
    head = new_solution.insert_node(head, 5);
    
    int k = 2;
    head = new_solution.rotateRight(head, k);

    std::cout << "Sorted linked list: " << new_solution.printList(head) << std::endl;

}
