class Solution(object):
    def missingNumber(self, nums):
        num = sorted(nums)
        for i in range(len(num)):
            if num[i] != i:
                return i
        return len(num)


def main():
    n = int(input("Enter number of elements: "))

    print("Enter the numbers separated by space:")
    nums = list(map(int, input().split()))

    sol = Solution()

    result = sol.missingNumber(nums)

    print("Missing number is:", result)


if __name__ == "__main__":
    main()
