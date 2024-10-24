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
    // Function to remove elements with a specific value
    ListNode* removeElements(ListNode* head, int val) {
        while (head && head->val == val) {
            head = head->next;
        }

        ListNode* temp = head;
        while (temp && temp->next) {
            if (temp->next->val == val)
                temp->next = temp->next->next;
            else
                temp = temp->next;
        }

        return head;
    }

    // Corrected insertNode function, with head passed by reference
    void insertNode(ListNode*& head, int new_val) {
        // Create a new node with the given value
        ListNode* newNode = new ListNode(new_val);

        // If the list is empty, the new node becomes the head
        if (!head) {
            head = newNode;
            return;
        }

        // Traverse to the end of the list
        ListNode* temp = head;
        while (temp->next) {
            temp = temp->next;
        }

        // Insert the new node at the end of the list
        temp->next = newNode;
    }

    // Function to print the linked list
    void printList(ListNode* head) {
        ListNode* temp = head;
        while (temp) {  // Fix to ensure it prints all elements
            std::cout << temp->val << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    ListNode* head = NULL;
    Solution s;
    s.insertNode(head, 1);
    s.insertNode(head, 2);
    s.insertNode(head, 3);
    s.insertNode(head, 6);
    s.insertNode(head, 4);
    s.insertNode(head, 5);
    s.insertNode(head, 6);

    // Removing elements with value 6
    head = s.removeElements(head, 6);

    // Print the updated list
    s.printList(head);

    return 0;
}
