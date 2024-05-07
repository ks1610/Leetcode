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
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode dummy(0);
    ListNode* curr = &dummy;
    int carry = 0;

    while (l1 != nullptr || l2 != nullptr || carry > 0) {
      if (l1 != nullptr) {
        carry += l1->val;
        l1 = l1->next;
      }
      if (l2 != nullptr) {
        carry += l2->val;
        l2 = l2->next;
      }
      curr->next = new ListNode(carry % 10);
      carry /= 10;
      curr = curr->next;
    }

    return dummy.next;
  }
};

int main() {
  // Example usage
  ListNode* l1 = new ListNode(2);
  l1->next = new ListNode(4);
  l1->next->next = new ListNode(3);

  ListNode* l2 = new ListNode(5);
  l2->next = new ListNode(6);
  l2->next->next = new ListNode(4);

  Solution solution;
  ListNode* result = solution.addTwoNumbers(l1, l2);

  std::cout << "Result: ";
  while (result != nullptr) {
    std::cout << result->val;
    result = result->next;
    if (result != nullptr) std::cout << " -> ";
  }
  std::cout << std::endl;

  // Clean up memory
  while (l1 != nullptr) {
    ListNode* temp = l1;
    l1 = l1->next;
    delete temp;
  }

  while (l2 != nullptr) {
    ListNode* temp = l2;
    l2 = l2->next;
    delete temp;
  }

  return 0;
}
