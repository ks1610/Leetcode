class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution(object):
    def Possible(self, node, min, max):  
        if not node:
            return True 
        if not (min < node.val < max):
            return False
        return self.Possible(node.left, min, node.val) and self.Possible(node.right, node.val, max)
    def isValidBST(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: bool
        """
        minval = float('-inf')
        maxval = float('inf')
        return self.Possible(root, minval, maxval)

# Test Case:
root = TreeNode(5)
root.left = TreeNode(1)
root.right = TreeNode(4)
root.right.left = TreeNode(3)
root.right.right = TreeNode(6)

sol = Solution()

print("Valid BST" if sol.isValidBST(root) else "Invalid BST")  # Output: Invalid BST
