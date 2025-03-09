class Solution(object):
    def numTrees(self, n):
        """
        :type n: int
        :rtype: int
        """
        uniqtree = [1] * (n + 1)
        for node in range(2, n + 1):
            total = 0
            for root in range(1, node + 1):
                total += uniqtree[root - 1] * uniqtree[node - root]
            uniqtree[node] = total

        return uniqtree[n]

n = 3
s = Solution()
print("Unique Binary Search Trees Of", n,":",s.numTrees(n))

#py Solution.py
