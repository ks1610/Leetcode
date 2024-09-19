#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

bool hasCycle(struct ListNode *head) {
    if(head == NULL || head-> next == NULL)
        return false;
    
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    while(fast != NULL && fast-> next != NULL){
        fast = fast->next->next;
        slow = slow-> next;
        if(fast == slow)
            return true;
    }
    return false;
}


struct ListNode* insert_node(struct ListNode* head, int value) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode)); 
    newNode->val = value;
    newNode->next = NULL;
    
    if(head == NULL)
        return newNode; 
    else {        
        struct ListNode* temp = head;
        while(temp->next) {
            temp = temp->next;
        }   
        temp->next = newNode;
        return head;
    }
}


int main() {
    struct ListNode* head = NULL;
    
    head = insert_node(head, 3);
    head = insert_node(head, 2);
    head = insert_node(head, 0);
    head = insert_node(head, -4);

    struct ListNode* current = head;

    // Manually creating a cycle: pointing the last node (4) back to the second node (2)
    printf("List: ");
    while (current->next != NULL) {
        printf("%d ", current->val);
        current = current->next;
    }
    current->next = head->next;// Creates a cycle by pointing the last node to the second node
    printf("%d\n", current->val); 

    printf("Is Circle? ");
    if(hasCycle(head))
        printf("true\n");
    else 
        printf("false\n");

    return 0;
}

