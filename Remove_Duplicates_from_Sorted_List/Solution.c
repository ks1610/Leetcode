#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* curr = head;
    struct ListNode*z;
    if(head==NULL)
    return head;
    int i;
    for(i = 0; i < 5; i++){
        while(curr->next != NULL){
            z = curr;
            curr = curr->next;
            if(z->val == curr->val)
                z->next = curr->next;
        }
        curr = head;
    }
    return head;
}

struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode; 
    
}

void printList(struct ListNode* head){
    struct ListNode* temp = head;
    while(temp != NULL){
        printf("%d", temp->val);
        temp = temp->next;
    }
    printf("\n");
}

void freeList(struct ListNode* head){
    struct ListNode* temp;
    while(head != NULL){
        temp = head;
        head = head->next;
        free(temp);
    }
}
int main(){ 
    struct ListNode* head = createNode(1);
    head->next = createNode(1);
    head->next->next = createNode(2);
    head->next->next->next = createNode(3);
    head->next->next->next->next = createNode(3);

    // Delete duplicates
    head = deleteDuplicates(head);

    // Print the result
    printList(head);

    // Free the allocated memory
    freeList(head);
    
}
