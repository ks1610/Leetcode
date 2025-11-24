class Solution(object):
    def pivotIndex(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        prefix = [0] * (n+1)
        for i in range(1, n+1):
            prefix[i] = prefix[i-1] + nums[i-1]
        total = prefix[n]
        for i in range(n):
            left = prefix[i]
            right = total - prefix[i+1]
            if right == left:
                return i 
        return -1

def main():
    s = Solution()
    nums = list(map(int, input("Enter numbers: ").split()))
    print("Pivot index:", s.pivotIndex(nums))

if __name__ == "__main__":
    main()
