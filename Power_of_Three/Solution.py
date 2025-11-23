class Solution(object):
    def isPowerOfThree(self, n):
        """
        :type n: int
        :rtype: bool
        """
        if n <= 0:
            return False 
        while n % 3 == 0:
            n /= 3
        return n == 1


if __name__ == "__main__":
    sol = Solution()

    # Test values
    nums = [1, 3, 9, 27, 10, 0, -3, 81, 82]

    for x in nums:
        print("isPowerOfThree({}): {}".format(x, sol.isPowerOfThree(x)))
