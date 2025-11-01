#include <bits/stdc++.h>


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int found = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target)
                found = i;
        }
        return found;
    }
};

int main() {
    Solution sol;
    std::vector<int> nums = {1, 3, 5, 7, 9, 5};
    int target;

    std::cout << "Enter target value: ";
    std::cin >> target;

    int index = sol.search(nums, target);

    if (index != -1)
        std::cout << "Target " << target << " found at index: " << index << std::endl;
    else
        std::cout << "Target " << target << " not found in array." << std::endl;

    return 0;
}
