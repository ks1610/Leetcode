class Solution(object):
    def majorityElement(self, nums):
        nums.sort()
        found = []
        count = 1
        n = len(nums)

        if n <= 2:
            for i in range(n):
                found.append(nums[i])
        else:
            for i in range(1, n):
                if nums[i] == nums[i - 1]:
                    count += 1

                if count > len(nums) // 3:
                    found.append(nums[i])
                    count = 0

                if nums[i] != nums[i - 1]:
                    count = 1

        if len(found) > 0:
            for x in range(0, len(found)-1):
                if found[x] == found[x + 1]:
                    del found[0]

        return found


# test main
if __name__ == "__main__":
    sol = Solution()

    nums = [3, 3, 3, 3, 3, 3, 3]
    # nums = [2, 2, 2, 3, 3]

    result = sol.majorityElement(nums)

    print("Majority elements (> n/3):", result)
