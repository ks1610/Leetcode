import unittest

class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
      
class Solution(object):
    def isSymmetric(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: bool
        """
        return self.isVaild(root.left, root.right)
    def isVaild(self, node_1, node_2):
        if node_1 is None and node_2 is None:
            return True
        if node_1 is None or node_2 is None:
            return False        
        return node_1.val == node_2.val and self.isVaild(node_1.left, node_2.right) and self.isVaild(node_1.right, node_2.left)

  class TestIsSymmetric(unittest.TestCase):
    def setUp(self):
        self.solution = Solution()

    def test_symmetric_tree(self):
        # Tree:
        #       1
        #      / \
        #     2   2
        #    / \ / \
        #   3  4 4  3
        tree = TreeNode(1,
                        TreeNode(2, TreeNode(3), TreeNode(4)),
                        TreeNode(2, TreeNode(4), TreeNode(3)))
        self.assertTrue(self.solution.isSymmetric(tree))

    def test_not_symmetric_tree(self):
        # Tree:
        #       1
        #      / \
        #     2   2
        #      \   \
        #       3   3
        tree = TreeNode(1,
                        TreeNode(2, None, TreeNode(3)),
                        TreeNode(2, None, TreeNode(3)))
        self.assertFalse(self.solution.isSymmetric(tree))

    def test_empty_tree(self):
        tree = TreeNode()  # Just a single root node
        self.assertTrue(self.solution.isSymmetric(tree))

    def test_single_node(self):
        tree = TreeNode(1)
        self.assertTrue(self.solution.isSymmetric(tree))

    def test_asymmetric_subtree(self):
        # Tree:
        #       1
        #      / \
        #     2   2
        #    /     \
        #   3       3
        tree = TreeNode(1,
                        TreeNode(2, TreeNode(3), None),
                        TreeNode(2, None, TreeNode(3)))
        self.assertTrue(self.solution.isSymmetric(tree))

if __name__ == "__main__":
    unittest.main()
