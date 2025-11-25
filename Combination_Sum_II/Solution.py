class Solution(object):
    def bt(self, can, total, com, re, pos):
        if total == 0:
            re.append(list(com))
            return
        if total < 0:
            return
        for i in range(pos, len(can)):
            if can[i] > total:
                break
            if i > pos and can[i] == can[i-1]:
                continue
            com.append(can[i])
            self.bt(can, total-can[i], com, re, i+1)
            com.pop()
    def combinationSum2(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        candidates.sort()
        result = []
        com = []
        self.bt(candidates, target, com, result, 0)
        return result
      
if __name__ == "__main__":
    s = Solution()
    nums = [10,1,2,7,6,1,5]
    target = 8

    result = s.combinationSum2(nums, target)

    print("Combination Sum:")
    for combo in result:
        print(combo)
