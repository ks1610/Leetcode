# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution(object):
    def sideHeight(self, node):
        if not node:
            return 0 
        leftHeight = self.sideHeight(node.left)
        if leftHeight == -1:
            return -1
        rightHeight = self.sideHeight(node.right)
        if rightHeight == -1:
            return -1
        return 1 + max(rightHeight, leftHeight) 
    def isBalanced(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: bool
        """
        if not root:
            return True
        leftHeight = self.sideHeight(root.left)
        rightHeight = self.sideHeight(root.right)
        if abs(leftHeight - rightHeight) > 1:
            return False
        return self.isBalanced(root.left) and self.isBalanced(root.right)
    

# Example Tree: [1, 2, 3, 4, None, None, 5]
tree = TreeNode(1)
tree.left = TreeNode(2, TreeNode(4))
tree.right = TreeNode(3, None, TreeNode(5))

sol = Solution()
print(sol.isBalanced(tree))  # Output: True or False depending on structure
