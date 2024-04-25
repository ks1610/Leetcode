#include <bits/stdc++.h>
#include <vector>

class Solution {
public:
    void nextPermutation(std::vector<int>& nums) {
        int n = nums.size();
        // Step 1: Find the break point:
        int idx = -1;
        for(int i = n-2; i >= 0; i--){
            if(nums[i] < nums[i+1]){
                idx = i;
                break;
            }
        }

        if(idx != -1){
            // Step 2: Find the next greater element and swap it with nums[idx]:
            for(int i = n-1; i > idx; i--){
                if(nums[i] > nums[idx]){
                    std::swap(nums[i], nums[idx]);
                    break;
                }
            }
        }
        // Reverse the right half
        reverse(nums.begin() + idx + 1, nums.end());

        //Other solution:        
        //next_permutation(nums.begin(),nums.end());
    }
};


int main() {
    std::vector<int> nums = {1, 2, 3}; // Example input vector

    Solution solution; // Create an instance of the Solution class

    // Display the original vector
    std::cout << "Original Vector: ";
    for (int num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Call the nextPermutation method to find the next permutation
    solution.nextPermutation(nums);

    // Display the next permutation
    std::cout << "Next Permutation: ";
    for (int num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
