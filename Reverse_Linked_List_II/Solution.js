// Definition for singly-linked list.
function ListNode(val, next) {
    this.val = (val === undefined ? 0 : val);
    this.next = (next === undefined ? null : next);
}

// Function to reverse the linked list between left and right positions
var reverseBetween = function(head, left, right) {
    if (!head || left === right)
        return head;

    const dump = new ListNode(0);
    dump.next = head;
    let prev = dump;

    // Move 'prev' to the node just before the 'left' position
    for (let i = 0; i < left - 1; i++) {
        prev = prev.next;
    }

    let curr = prev.next;

    // Reverse the nodes between 'left' and 'right'
    for (let i = 0; i < right - left; i++) {
        const temp = curr.next;
        curr.next = temp.next;
        temp.next = prev.next;
        prev.next = temp;
    }

    return dump.next;
};

// Utility function to print the linked list
function printList(head) {
    let current = head;
    let result = [];
    while (current !== null) {
        result.push(current.val);
        current = current.next;
    }
    console.log(result.join(' -> '));
}

// Utility function to create a linked list from an array
function createList(arr) {
    if (arr.length === 0) return null;
    let head = new ListNode(arr[0]);
    let current = head;
    for (let i = 1; i < arr.length; i++) {
        current.next = new ListNode(arr[i]);
        current = current.next;
    }
    return head;
}

// Test case
let head = createList([1, 2, 3, 4, 5]);

console.log("Original list:");
printList(head);

// Perform reverse between position 2 and 4
head = reverseBetween(head, 2, 4);

console.log("List after reversing between positions 2 and 4:");
printList(head);
