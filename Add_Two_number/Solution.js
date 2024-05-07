// Definition for singly-linked list node
function ListNode(val, next) {
    this.val = (val === undefined ? 0 : val);
    this.next = (next === undefined ? null : next);
}

// Function to add two numbers represented by linked lists
var addTwoNumbers = function(l1, l2, carry) {
    if (!l1 && !l2 && !carry) return null;

    var total = (l1 ? l1.val : 0) + (l2 ? l2.val : 0) + (carry || 0);
    carry = Math.floor(total / 10);
    
    return new ListNode(total % 10, addTwoNumbers(l1?.next, l2?.next, carry));
};

// Example usage:
// Create linked list nodes
const l1 = new ListNode(2);
l1.next = new ListNode(4);
l1.next.next = new ListNode(3);

const l2 = new ListNode(5);
l2.next = new ListNode(6);
l2.next.next = new ListNode(4);

// Call the function to add the numbers
const result = addTwoNumbers(l1, l2);

// Helper function to convert linked list to array for display
function linkedListToArray(head) {
    let arr = [];
    let current = head;
    while (current !== null) {
        arr.push(current.val);
        current = current.next;
    }
    return arr;
}

// Convert the result linked list to an array for better visualization
const resultArray = linkedListToArray(result);

console.log(resultArray); // Output: [7, 0, 8]
