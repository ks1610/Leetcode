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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* p1=list1;
        ListNode* p2=list2;
        ListNode* temp= new ListNode(-1);
        ListNode* p3=temp;
        
        while(p1!=NULL && p2!=NULL){
            if(p1->val < p2->val){
                p3->next=p1;
                p1=p1->next;
            }
            else{
                p3->next=p2;
                p2=p2->next;
            }
            p3=p3->next;
        }

        while(p1!=NULL){
            p3->next=p1;
            p1=p1->next;
            p3=p3->next;
        }
        
        while(p2!=NULL){
            p3->next=p2;
            p2=p2->next;
            p3=p3->next;
        }

        return temp->next;
    }
};

int main() {
    // Create the first sorted linked list: 1 -> 3 -> 5
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(3);
    list1->next->next = new ListNode(5);

    // Create the second sorted linked list: 2 -> 4 -> 6
    ListNode* list2 = new ListNode(2);
    list2->next = new ListNode(4);
    list2->next->next = new ListNode(6);

    Solution solution;

    // Merge the two sorted lists
    ListNode* mergedList = solution.mergeTwoLists(list1, list2);

    // Output the merged list
    ListNode* current = mergedList;
    while (current != nullptr) {
        std::cout << current->val;
        if (current->next != nullptr) {
            std::cout << " -> ";
        }
        current = current->next;
    }
    std::cout << std::endl;

    // Clean up: free allocated memory
    current = mergedList;
    while (current != nullptr) {
        ListNode* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}
