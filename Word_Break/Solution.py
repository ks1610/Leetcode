class Solution:
    def wordBreak(self, s, wordDict):
        dp = [True] + [False] * len(s)

        for i in range(1, len(s) + 1):
            for w in wordDict:
                start = i - len(w)
                if start >= 0 and dp[start] and s[start:i] == w:
                    dp[i] = True
                    break

        return dp[-1]

# Test cases
test_cases = [
    ("leetcode", ["leet", "code"], True),
    ("applepenapple", ["apple", "pen"], True),
    ("catsandog", ["cats", "dog", "sand", "and", "cat"], False),
    ("", [], True),  # Edge case: empty string and empty wordDict
    ("a", ["a"], True),  # Single character match
    ("b", ["a"], False),  # Single character no match
    ("bb", ["b", "bbb"], True),  # Multiple character match
]

# Initialize Solution
sol = Solution()

# Run tests
for i, (s, wordDict, expected) in enumerate(test_cases):
    result = sol.wordBreak(s, wordDict)
    print(f"Test case {i + 1}: {'Passed' if result == expected else 'Failed'}")
    print(f"Input: s = '{s}', wordDict = {wordDict}")
    print(f"Expected: {expected}, Got: {result}")
    print()
