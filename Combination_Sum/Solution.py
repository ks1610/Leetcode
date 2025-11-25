class Solution(object):
    def bt(self, can, total, com, re, pos):
        if total == 0:
            re.append(list(com))
            return
        if total < 0:
            return
        for i in range(pos, len(can)):
            com.append(can[i])
            self.bt(can, total-can[i], com, re, i)
            com.pop()
    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        result = []
        com = []
        self.bt(candidates, target, com, result, 0)
        return result

        

if __name__ == "__main__":
    s = Solution()
    nums = [2, 3, 6, 7]
    target = 7

    result = s.combinationSum(nums, target)

    print("Combination Sum:")
    for combo in result:
        print(combo)
