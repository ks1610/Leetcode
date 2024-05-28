#include <iostream>
#include <vector>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        int j = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (j == 1 || nums[i] != nums[j - 2]) {
                nums[j++] = nums[i];
            }
        }
        return j;
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = {1, 1, 1, 2, 2, 3, 3, 4, 4, 4, 5};

    std::cout << "Original array: ";
    for (int num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    int newLength = solution.removeDuplicates(nums);

    std::cout << "Array after removing duplicates: ";
    for (int i = 0; i < newLength; i++) {
        std::cout << nums[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "New length: " << newLength << std::endl;

    return 0;
}
