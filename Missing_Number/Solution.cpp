#include<bits/stdc++.h>

class Solution {
public:
    int missingNumber(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int result;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != i) {
                return i;
            }
        }
        return nums.size();
    }
};

int main() {
    int n;
    std::cout << "Enter number of elements: ";
    std::cin >> n;

    std::vector<int> nums(n);
    std::cout << "Enter " << n << " numbers:\n";
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }

    Solution sol;
    int missing = sol.missingNumber(nums);

    std::cout << "Missing number is: " << missing << std::endl;

    return 0;
}
