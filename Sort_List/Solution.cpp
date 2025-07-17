#include <iostream>
#include <vector>
#include <algorithm>  // Optional, not used if using custom sort

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    std::vector<int> merge_sort(std::vector<int>& arr, int left, int right) {
        if (left >= right) return {arr[left]};

        int mid = left + (right - left) / 2;

        std::vector<int> left_half = merge_sort(arr, left, mid);
        std::vector<int> right_half = merge_sort(arr, mid + 1, right);

        // Merge two sorted halves
        std::vector<int> result;
        int i = 0, j = 0;

        while (i < left_half.size() && j < right_half.size()) {
            if (left_half[i] < right_half[j])
                result.push_back(left_half[i++]);
            else
                result.push_back(right_half[j++]);
        }

        while (i < left_half.size()) result.push_back(left_half[i++]);
        while (j < right_half.size()) result.push_back(right_half[j++]);

        return result;
    }

    std::vector<int> sort_func(std::vector<int> arr) {
        if (arr.empty()) return {};
        return merge_sort(arr, 0, arr.size() - 1);
    }

    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;

        std::vector<int> order;
        ListNode* temp = head;

        while (temp) {
            order.push_back(temp->val);
            temp = temp->next;
        }

        order = sort_func(order);  // Use your custom merge sort

        temp = head;
        int i = 0;
        while (temp) {
            temp->val = order[i++];
            temp = temp->next;
        }

        return head;
    }
};

// Utility function to create linked list from vector
ListNode* createList(const std::vector<int>& values) {
    if (values.empty()) return nullptr;
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;

    for (size_t i = 1; i < values.size(); ++i) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }

    return head;
}

// Utility function to print linked list
void printList(ListNode* head) {
    while (head) {
        std::cout << head->val;
        if (head->next) std::cout << " -> ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    // Example input
    std::vector<int> input = {4, 2, 1, 3};

    ListNode* head = createList(input);

    std::cout << "Original list: ";
    printList(head);

    Solution sol;
    ListNode* sorted = sol.sortList(head);

    std::cout << "Sorted list: ";
    printList(sorted);

    return 0;
}
