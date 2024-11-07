#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1])
                return true;
        }
        return false;
    }
};

int main() {
    Solution s;
    std::vector<int> nums = {1, 2, 3, 1};
    std::cout << (s.containsDuplicate(nums) ? "true" : "false") << std::endl;

    nums = {1, 2, 3, 4};
    std::cout << (s.containsDuplicate(nums) ? "true" : "false") << std::endl;

    nums = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
    std::cout << (s.containsDuplicate(nums) ? "true" : "false") << std::endl;

    return 0;
}
