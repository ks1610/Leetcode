class Solution(object):
    def isUgly(self, n):
        """
        :type n: int
        :rtype: bool
        """
        if n <= 0:
            return False
        while n % 2 == 0:
            n //= 2   # use integer division
        while n % 3 == 0:
            n //= 3
        while n % 5 == 0:
            n //= 5
        return n == 1

# ==== Testing ====
if __name__ == "__main__":
    nums = [6, 8, 14, 1, 0, -5]
    sol = Solution()
    for n in nums:
        print(n, "->", sol.isUgly(n))
