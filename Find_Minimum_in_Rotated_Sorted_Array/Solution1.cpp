#include <bits/stdc++.h>

class Solution {
public:
    int findMin(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        return nums[0]; 
    }
};


int main() {
     Solution s;
     std::vector<int> nums = {10,1,2,7,6,1,5};
     int target = 8;
     std::cout<< "Find Min: "<< s.findMin(nums) <<std::endl;
     return 0;
}

