#include <bits/stdc++.h>

class Solution {
public:
    int findMin(vector<int>& nums) {
        // std::sort(nums.begin(), nums.end());
        // return nums[0]; 
        int left = 0;
        int right = nums.size()-1;
        while(left < right){
            int mid = left+(right-left)/2;
            if(nums[mid] <= nums[right])
                right = mid;
            else
                left = mid+1;
        }
        return nums[left];
    }
};


int main() {
     Solution s;
     std::vector<int> nums = {10,1,2,7,6,1,5};
     int target = 8;
     std::cout<< "Find Min: "<< s.findMin(nums) <<std::endl;
     return 0;
}

