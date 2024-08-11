class Solution(object):
    def findPeakElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) == 1:
            return 0
        if nums[0] > nums[1]:
            return 0
        if nums[len(nums) - 1] > nums[len(nums) - 2]:
            return len(nums) - 1
        
        left = 0
        right = len(nums) - 1
        
        while left <= right:
            mid = left + (right - left) // 2
            
            if mid > 0 and mid < len(nums) - 1:
                if nums[mid] > nums[mid + 1] and nums[mid] > nums[mid - 1]:
                    return mid
                elif nums[mid] > nums[mid + 1]:
                    right = mid - 1
                else:
                    left = mid + 1
            elif mid == 0:
                if nums[mid] > nums[mid + 1]:
                    return mid
                else:
                    return mid + 1
            elif mid == len(nums) - 1:
                if nums[mid] > nums[mid - 1]:
                    return mid
                else:
                    return mid - 1

        return -1  # This should never be reached if the input is valid

# Test cases
def test_find_peak_element():
    solution = Solution()
    
    # Test case 1
    nums = [1, 2, 3, 1]
    result = solution.findPeakElement(nums)
    print(f"Test case 1 - Expected: 2, Got: {result}")
    
    # Test case 2
    nums = [1, 2, 1, 3, 5, 6, 4]
    result = solution.findPeakElement(nums)
    print(f"Test case 2 - Expected: 5, Got: {result}")
    
    # Test case 3
    nums = [1, 3, 20, 4, 1, 0]
    result = solution.findPeakElement(nums)
    print(f"Test case 3 - Expected: 2, Got: {result}")
    
    # Test case 4
    nums = [10, 20, 30, 40, 50]
    result = solution.findPeakElement(nums)
    print(f"Test case 4 - Expected: 4, Got: {result}")
    
    # Test case 5
    nums = [50, 40, 30, 20, 10]
    result = solution.findPeakElement(nums)
    print(f"Test case 5 - Expected: 0, Got: {result}")
    
    # Test case 6: Single element
    nums = [10]
    result = solution.findPeakElement(nums)
    print(f"Test case 6 - Expected: 0, Got: {result}")
    
    # Test case 7: Two elements
    nums = [1, 2]
    result = solution.findPeakElement(nums)
    print(f"Test case 7 - Expected: 1, Got: {result}")
    
    # Test case 8: Multiple peaks
    nums = [1, 2, 3, 2, 4, 3]
    result = solution.findPeakElement(nums)
    print(f"Test case 8 - Expected: 2 or 4, Got: {result}")
    
    # Test case 9: Larger array
    nums = [10, 11, 12, 13, 9, 7, 8, 6, 4, 2, 1]
    result = solution.findPeakElement(nums)
    print(f"Test case 9 - Expected: 3 or 2, Got: {result}")

if __name__ == "__main__":
    test_find_peak_element()
