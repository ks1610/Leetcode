#include <bits/stdc++.h>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp=head;
        int count = 0;

        while(temp!=NULL){
            count++;
            temp = temp->next;
        }

        if(count==n) return head->next;

        ListNode* prev=NULL;
        ListNode* curr=head;
        
        int i=0;
        while(i!=count-n && curr!=NULL)
        {
            i++;
            prev=curr;
            curr=curr->next;
        }
        prev->next=curr->next;
        return head;

    }
};

int main() {
    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution solution;

    // Call the removeNthFromEnd method to remove the 2nd node from the end (i.e., node with value 4)
    int n = 2;
    ListNode* result = solution.removeNthFromEnd(head, n);

    // Output the resulting linked list after removal
    ListNode* current = result;
    while (current != nullptr) {
        std::cout << current->val << " -> ";
        current = current->next;
    }
    std::cout << "nullptr" << std::endl;

    // Clean up: free allocated memory
    current = result;
    while (current != nullptr) {
        ListNode* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}
