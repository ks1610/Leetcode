class Solution(object):
    def findMin(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        l = 0
        r = len(nums) -1
        while l < r:
            mid = l+(r - l)/2
            if nums[mid] <= nums[r]:
                r = mid
            else: 
                l = mid+1
        return nums[l] 
      
  if __name__ == "__main__":
    s = Solution()

    nums = [3, 4, 5, 1, 2] 
    result = s.findMin(nums)

    print("Minimum element is:", result)
