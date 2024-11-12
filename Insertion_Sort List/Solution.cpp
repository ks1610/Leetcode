#include <iostream>
#include <vector>
#include <algorithm>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* sorted = nullptr; // Start with an empty sorted list

        // Traverse the original list and insert each element into the sorted list
        while (head != nullptr) {
            ListNode* current = head;  // The node to be inserted
            head = head->next;  // Advance head to the next node
            
            // Insert current into the sorted list
            if (sorted == nullptr || sorted->val >= current->val) {
                current->next = sorted;
                sorted = current;
            } else {
                ListNode* temp = sorted;
                // Find the appropriate position to insert the current node
                while (temp->next != nullptr && temp->next->val < current->val) {
                    temp = temp->next;
                }
                current->next = temp->next;
                temp->next = current;
            }
        }

        return sorted;
    }

    void printlist(ListNode* head) {
        ListNode* temp = head;
        while (temp != nullptr) {
            std::cout << temp->val << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

int main(){
    ListNode* head = new ListNode(5);
    head->next = new ListNode(4);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);
    head->next->next->next->next = new ListNode(3);

    Solution s;
    std::cout<<"Before: ";
    s.printlist(head);
    std::cout<<std::endl;

    head = s.insertionSortList(head);

    std::cout<<"After: ";
    s.printlist(head);
    // Free allocated memory

    ListNode* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }

}
