# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution(object):
    def reverseBetween(self, head, left, right):
        """
        :type head: ListNode
        :type left: int
        :type right: int
        :rtype: ListNode
        """
        if not head or left == right:
            return head

        dump = ListNode(0)  # Create a dummy node to simplify edge cases
        dump.next = head
        prev = dump

        # Move `prev` to the node just before the `left` position
        for _ in range(left - 1):
            prev = prev.next

        # `curr` will point to the node at `left` position
        curr = prev.next

        # Reverse the sublist from `left` to `right`
        for _ in range(right - left):
            temp = curr.next
            curr.next = temp.next
            temp.next = prev.next
            prev.next = temp

        return dump.next

# Helper function to print the linked list
def print_list(head):
    result = []
    while head:
        result.append(str(head.val))
        head = head.next
    print(" -> ".join(result))

# Helper function to create a linked list from a list of values
def create_linked_list(arr):
    if not arr:
        return None
    head = ListNode(arr[0])
    current = head
    for value in arr[1:]:
        current.next = ListNode(value)
        current = current.next
    return head

# Test the reverseBetween function
if __name__ == "__main__":
    # Create the linked list [1, 2, 3, 4, 5]
    head = create_linked_list([1, 2, 3, 4, 5])
    print("Original list:")
    print_list(head)

    # Perform reverse between position 2 and 4
    solution = Solution()
    new_head = solution.reverseBetween(head, 2, 4)
    print("List after reversing between positions 2 and 4:")
    print_list(new_head)
