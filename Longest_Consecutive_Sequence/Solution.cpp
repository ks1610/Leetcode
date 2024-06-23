#include <bits/stdc++.h>

class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        if(nums.empty())
            return 0;

        std::sort(nums.begin(), nums.end());

        int longest = 1;
        int current = 1;

        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == nums[i - 1])
                continue;
            else if(nums[i] == nums[i - 1] + 1)
                current++;
            else {
                longest = std::max(longest, current);
                current = 1;
            }
        }

        return std::max(longest, current);
    }
};

// Example usage
int main() {
    Solution sol;
    std::vector<int> nums = {100, 4, 200, 1, 3, 2};
    std::cout << "Longest consecutive sequence length: " << sol.longestConsecutive(nums) << std::endl;
    return 0;
}
