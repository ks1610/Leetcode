class Solution(object):
    def uniquePaths(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        result = 1

        # Choose the smaller of m-1 and n-1 for efficient calculation
        k = min(m - 1, n - 1)

        # Compute the binomial coefficient (m+n-2) choose (m-1) or (n-1)
        for i in range(1, k + 1):
            result = result * (m + n - 2 - i + 1) // i

        return result


def test_uniquePaths():
    sol = Solution()

    # Test cases
    assert sol.uniquePaths(3, 7) == 28
    assert sol.uniquePaths(3, 2) == 3
    assert sol.uniquePaths(7, 3) == 28
    assert sol.uniquePaths(3, 3) == 6

    print("All test cases passed!")

test_uniquePaths()
