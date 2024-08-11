/*
Runtime: 0ms
Beats: 100.00%

Memory: 11.70MB
Beats: 6.55%
*/

#include <bits/stdc++.h>

class Solution {
public:
    int findPeakElement(std::vector<int>& nums) {
        if(nums.size()==1){
            return 0;
        }
        if(nums[0]>nums[1]){
            return 0;
        }
        else if(nums[nums.size()-1]>nums[nums.size()-2]){
            return nums.size()-1;
        }
        int left = 0, right = nums.size() - 1;
        while(left <= right){
            int mid = left + (right - left)/2;
            if(nums[mid] > nums[mid + 1] && nums[mid] > nums[mid - 1])
                return mid;
            else if(nums[mid] > nums[mid + 1])
                right = mid - 1;
            else 
                left = mid + 1;
        }
        return -1;
    }
};

int main() {
    Solution solution;
    
    std::vector<int> test1 = {1, 2, 3, 1};
    std::vector<int> test2 = {1, 2, 1, 3, 5, 6, 4};
    std::vector<int> test3 = {1, 3, 20, 4, 1, 0};
    std::vector<int> test4 = {10, 20, 30, 40, 50};
    std::vector<int> test5 = {50, 40, 30, 20, 10};

    std::cout << "Test 1 Peak Index: " << solution.findPeakElement(test1) << std::endl;  // Expected: 2
    std::cout << "Test 2 Peak Index: " << solution.findPeakElement(test2) << std::endl;  // Expected: 5
    std::cout << "Test 3 Peak Index: " << solution.findPeakElement(test3) << std::endl;  // Expected: 2
    std::cout << "Test 4 Peak Index: " << solution.findPeakElement(test4) << std::endl;  // Expected: 4
    std::cout << "Test 5 Peak Index: " << solution.findPeakElement(test5) << std::endl;  // Expected: 0

    return 0;
}
