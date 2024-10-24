# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution(object):
    def removeElements(self, head, val):
        """
        :type head: Optional[ListNode]
        :type val: int
        :rtype: Optional[ListNode]
        """
        # Remove elements from the head if they match the target value
        while head and head.val == val:
            head = head.next  # Move head to the next node
        
        # Initialize a temporary pointer to traverse the list
        temp = head
        while temp and temp.next:
            if temp.next.val == val:
                # Bypass the node with the target value
                temp.next = temp.next.next
            else:
                # Move to the next node if no deletion
                temp = temp.next
        
        # Return the possibly updated head
        return head

    # Function to insert a new node at the end of the linked list
    def insertNode(self, head, new_val):
        new_node = ListNode(new_val)
        if not head:
            return new_node  # If list is empty, return the new node as head
        
        temp = head
        while temp.next:  # Traverse to the end of the list
            temp = temp.next
        
        temp.next = new_node  # Insert the new node at the end
        return head
    
    # Function to print the linked list
    def printList(self, head):
        temp = head
        while temp:
            print(temp.val, end=" -> " if temp.next else "")
            temp = temp.next
        print()  # New line after printing the list

# Testing the functions
if __name__ == "__main__":
    s = Solution()
    
    # Initialize the linked list with some values
    head = None
    for val in [1, 2, 6, 3, 4, 5, 6]:
        head = s.insertNode(head, val)

    print("Original List:")
    s.printList(head)

    # Remove elements with value 6
    head = s.removeElements(head, 6)

    print("List after removing 6:")
    s.printList(head)
