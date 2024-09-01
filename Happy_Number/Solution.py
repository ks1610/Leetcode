class Solution(object):
    def isHappy(self, n):
        """
        :type n: int
        :rtype: bool
        """
        while n > 9:
            x = 0
            while n != 0:
                a = n % 10
                n //= 10
                x += a * a
            n = x
        if n == 1 or n == 7:
            return True
        return False

def test_isHappy():
    solution = Solution()

    # Test cases
    assert solution.isHappy(19) == True, "Test case 1 failed"
    assert solution.isHappy(7) == True, "Test case 2 failed"
    assert solution.isHappy(2) == False, "Test case 3 failed"
    assert solution.isHappy(1) == True, "Test case 4 failed"
    assert solution.isHappy(1111111) == True, "Test case 5 failed"
    assert solution.isHappy(4) == False, "Test case 6 failed"

    print("All test cases passed!")

# Run the tests
test_isHappy()
