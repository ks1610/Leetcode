#include <iostream>
#include <vector>

// Including the Solution class
class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
        int result = 0;
        for (int num : nums) {
            result ^= num;
        }
        return result;
    }
};

int main() {
    // Creating an instance of Solution
    Solution solution;
    
    // Test case: Example array where all numbers except one appear twice
    std::vector<int> nums = {2, 3, 2, 4, 4, 3, 1};

    // Calling the singleNumber function
    int uniqueNumber = solution.singleNumber(nums);
    
    // Printing the result
    std::cout << "The single number is: " << uniqueNumber << std::endl;
    
    return 0;
}
