class Solution(object):
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        ans = [1] * len(nums)
        l = 1
        for i in range(len(nums)):
            ans[i] *= l
            l *= nums[i]

        r = 1
        for i in range(len(nums) - 1, -1, -1):
            ans[i] *= r
            r *= nums[i]
        
        return ans 

def main():
    sol = Solution()
    nums = [1, 2, 3, 4]
    result = sol.productExceptSelf(nums)
    print("Input:", nums)
    print("Output:", result)

if __name__ == "__main__":
    main()
