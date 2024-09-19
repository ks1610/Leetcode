#include<stdio.h>
#include<stdlib.h>


struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (head == NULL || head->next == NULL || k == 0)
        return head;
    int length = 1;
    struct ListNode* last = head;
    while(last->next != NULL)
    {
        last = last->next;
        length++;
    }
    k = k % length;
    if(k==0)
        return head;
    int newLastIndex = length - k - 1;
    struct ListNode* newLast = head;
    for (int i = 0; i < newLastIndex; ++i) {
        newLast = newLast->next;
    }
    struct ListNode* newHead = newLast->next;
    newLast->next = NULL;
    last->next = head;
    return newHead;
}

struct ListNode* insert_node(struct ListNode* head, int value){
        struct ListNode* newNode =  (struct ListNode*)malloc(sizeof(struct ListNode)); 
        newNode->val = value;
        newNode->next = NULL;
        if(head == NULL)
            return newNode; 
        else{        
            struct ListNode* temp = head;
            while(temp->next){
                temp = temp->next;
            }   

            temp->next = newNode;
            return head;
        }
}

void printList(struct ListNode* head) {
    struct ListNode* current = head;

    printf("Rotated list: ");
    while (current!= NULL) {
        printf("%d ", current->val);
        current = current->next;
    }
}

int main() {
    struct ListNode* head = NULL;
    head = insert_node(head, 1);
    head = insert_node(head, 2);
    head = insert_node(head, 3);
    head = insert_node(head, 4);
    head = insert_node(head, 5);

    int k = 2;
    head = rotateRight(head, k);

    // Print the linked list and get the size
    //int size = printList(head);
    printList(head);
    
    return 0;
}

