#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        std::unordered_map<int, int> mp;
        int n = nums.size() / 2;

        for(auto a : nums) {
            mp[a]++;
        }

        int ans = 0;
        for(auto a : mp) {
            if(a.second > n)
                ans = a.first;
        }

        return ans;
    }
};

void runTest(std::vector<int>& nums, int expected) {
    Solution sol;
    int result = sol.majorityElement(nums);
    std::cout << "Input: {";
    for(size_t i = 0; i < nums.size(); ++i) {
        std::cout << nums[i];
        if (i != nums.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "} -> Output: " << result << " (Expected: " << expected << ")" << std::endl;
}

int main() {
    std::vector<int> test1 = {3, 2, 3};
    std::vector<int> test2 = {2, 2, 1, 1, 1, 2, 2};
    std::vector<int> test3 = {1};
    std::vector<int> test4 = {1, 2, 3, 1, 1};

    runTest(test1, 3);    // Expected: 3
    runTest(test2, 2);    // Expected: 2
    runTest(test3, 1);    // Expected: 1
    runTest(test4, 1);    // Expected: 1

    return 0;
}
