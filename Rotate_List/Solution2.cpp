#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(NULL) {}
};

// Function to print the list and get its size
int printList(Node* head) {
    Node* current = head;

    while (current->next != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    return current->data;
}

Node* insert_node(Node* head, int value){
        Node* newNode = new Node(value); 
        if(head == NULL)
            return newNode; 
        else{        
            Node* temp = head;
            while(temp->next){
                temp = temp->next;
            }   

            temp->next = newNode;
            return head;
        }
}

Node* rotateRight(Node* head, int k) {
    if (head == nullptr || head->next == nullptr || k == 0)
        return head;
    
    int length = 1;
    Node* last = head;
    while(last->next != NULL)
    {
        last = last->next;
        length++;
    }
    
    k = k % length;
    if(k==0)
        return head;

    int newLastIndex = length - k - 1;
    Node* newLast = head;
    for (int i = 0; i < newLastIndex; ++i) {
        newLast = newLast->next;
    }

    Node* newHead = newLast->next;
    newLast->next = NULL;
    last->next = head;

    return newHead;
}

int main() {
    Node* head = NULL;
    head = insert_node(head, 1);
    head = insert_node(head, 2);
    head = insert_node(head, 3);
    head = insert_node(head, 4);
    head = insert_node(head, 5);

    int k = 2;
    head = rotateRight(head, k);

    // Print the linked list and get the size
    //int size = printList(head);
    cout << "Rotated list: " << printList(head) << endl;
    
    return 0;
}
