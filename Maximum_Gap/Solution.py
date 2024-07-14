class Solution(object):
    def maximumGap(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        x = []
        s = sorted(nums)
        if len(nums) < 2:
            return 0
        else:
            for i in range(len(s) - 1):
                x.append(s[i+1] - s[i])
        return max(x)

# Example inputs and outputs
sol = Solution()
print(sol.maximumGap([3, 6, 9, 1]))      # Output: 3
print(sol.maximumGap([10]))              # Output: 0
print(sol.maximumGap([10, 9, 8, 7]))     # Output: 1
print(sol.maximumGap([1, 10000000]))     # Output: 9999999
print(sol.maximumGap([1, 2, 3, 4, 5]))   # Output: 1
