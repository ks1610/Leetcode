class Solution(object):
    def compareVersion(self, version1, version2):
        """
        :type version1: str
        :type version2: str
        :rtype: int
        """
        version1 = [int(i) for i in version1.split(".")]
        version2 = [int(i) for i in version2.split(".")]

        if len(version1) < len(version2):
            currSize = (len(version2) - len(version1))
            version1 += [0] * currSize
        else:
            currSize = (len(version1) - len(version2))
            version2 += [0] * currSize
        
        makeCompare = (version1 > version2) - (version1 < version2)

        return makeCompare

# Instantiate the Solution class
solution = Solution()

# Test cases
test_cases = [
    ("1.01", "1.001", 0),
    ("1.0", "1.0.0", 0),
    ("0.1", "1.1", -1),
    ("1.2", "1.10", -1),
    ("2.1", "2.1.0", 0),
    ("1.2.3", "1.2.3.0", 0),
    ("3.4.5.6", "3.4.5", 1)
]

# Run the test cases
for version1, version2, expected in test_cases:
    result = solution.compareVersion(version1, version2)
    print(f"compareVersion('{version1}', '{version2}') = {result} (Expected: {expected})")
