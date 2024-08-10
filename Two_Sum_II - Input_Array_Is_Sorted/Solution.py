class Solution(object):
    def twoSum(self, numbers, target):
        """
        :type numbers: List[int]
        :type target: int
        :rtype: List[int]
        """
        left = 0
        right = len(numbers) - 1
        while left < right :
            if numbers[left] + numbers[right] == target :
                return [left+1, right+1]
            elif numbers[left] + numbers[right] < target :
                left+=1
            else: 
                right-=1

def test_two_sum():
    solution = Solution()

    # Test case 1: Simple case
    numbers = [2, 7, 11, 15]
    target = 9
    expected = [1, 2]
    assert solution.twoSum(numbers, target) == expected, f"Test case 1 failed: expected {expected}, got {solution.twoSum(numbers, target)}"

    # Test case 2: Negative numbers
    numbers = [-3, -2, -1, 0, 1, 2, 3]
    target = 0
    expected = [3, 6]
    assert solution.twoSum(numbers, target) == expected, f"Test case 2 failed: expected {expected}, got {solution.twoSum(numbers, target)}"

    # Test case 3: Single solution at the beginning
    numbers = [1, 2, 3, 4, 4]
    target = 8
    expected = [4, 5]
    assert solution.twoSum(numbers, target) == expected, f"Test case 3 failed: expected {expected}, got {solution.twoSum(numbers, target)}"

    # Test case 4: All negative numbers
    numbers = [-10, -7, -3, -1]
    target = -8
    expected = [2, 4]
    assert solution.twoSum(numbers, target) == expected, f"Test case 4 failed: expected {expected}, got {solution.twoSum(numbers, target)}"

    # Test case 5: Target in the middle of the list
    numbers = [1, 2, 3, 7, 11]
    target = 9
    expected = [2, 4]
    assert solution.twoSum(numbers, target) == expected, f"Test case 5 failed: expected {expected}, got {solution.twoSum(numbers, target)}"

    # Test case 6: Minimal case
    numbers = [2, 7]
    target = 9
    expected = [1, 2]
    assert solution.twoSum(numbers, target) == expected, f"Test case 6 failed: expected {expected}, got {solution.twoSum(numbers, target)}"

    print("All test cases passed!")

# Run the test
test_two_sum()
