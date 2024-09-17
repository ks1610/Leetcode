class TreeNode(object):
     def __init__(self, val=0, left=None, right=None):
         self.val = val
         self.left = left
         self.right = right

class Solution(object):
    def isSameTree(self, p, q):
        """
        :type p: TreeNode
        :type q: TreeNode
        :rtype: bool
        """
        if p is None and q is None:
            return True
        if p is None or q is None:
            return False
        if p.val == q.val:
            return self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right)
        return False

# Assuming TreeNode and Solution classes are already defined.

# Helper function to create a binary tree node
def create_tree_from_list(lst, i=0):
    """
    Creates a binary tree from a list of values. If the value is None, it means no child.
    :param lst: List of values where None indicates the absence of a node.
    :param i: Current index in the list.
    :return: Root node of the tree.
    """
    if i >= len(lst) or lst[i] is None:
        return None

    root = TreeNode(lst[i])
    root.left = create_tree_from_list(lst, 2 * i + 1)
    root.right = create_tree_from_list(lst, 2 * i + 2)
    return root

# Test cases
if __name__ == "__main__":
    sol = Solution()

    # Test Case 1: Identical trees
    tree1 = create_tree_from_list([1, 2, 3])
    tree2 = create_tree_from_list([1, 2, 3])
    print("Test Case 1: ", "Pass" if sol.isSameTree(tree1, tree2) else "Fail")  # Expected: Pass

    # Test Case 2: Trees with different structures
    tree3 = create_tree_from_list([1, 2])
    tree4 = create_tree_from_list([1, None, 2])
    print("Test Case 2: ", "Pass" if not sol.isSameTree(tree3, tree4) else "Fail")  # Expected: Pass

    # Test Case 3: Trees with different values
    tree5 = create_tree_from_list([1, 2, 1])
    tree6 = create_tree_from_list([1, 1, 2])
    print("Test Case 3: ", "Pass" if not sol.isSameTree(tree5, tree6) else "Fail")  # Expected: Pass

    # Test Case 4: Both trees are None
    tree7 = None
    tree8 = None
    print("Test Case 4: ", "Pass" if sol.isSameTree(tree7, tree8) else "Fail")  # Expected: Pass

        
        
