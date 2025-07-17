# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def sortList(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: Optional[ListNode]
        """

        if head is None or head.next is None:
            return head

        fast, slow = head.next, head
        while fast and fast.next:
            fast = fast.next.next
            slow = slow.next

        second = slow.next
        slow.next = None

        l = self.sortList(head)
        r = self.sortList(second)

        return self.merge(l, r)
  
    def merge(self, l, r):
        if l is None:
            return l
        elif r is None:
            return r
        
        dummy = ListNode(0)
        tail = dummy

        while l and r:
            if l.val <= r.val:
                tail.next = l
                l = l.next
            else:
                tail.next = r
                r = r.next
            tail = tail.next

        tail.next = l if l else r

        return dummy.next

# Helper functions for testing
def create_list(values):
    dummy = ListNode(0)
    curr = dummy
    for v in values:
        curr.next = ListNode(v)
        curr = curr.next
    return dummy.next

def print_list(head):
    while head:
        print(head.val, end=" -> " if head.next else "\n")
        head = head.next

# Test
head = create_list([4, 2, 1, 3])
sol = Solution()
sorted_head = sol.sortList(head)
print_list(sorted_head)  # Expected: 1 -> 2 -> 3 -> 4
