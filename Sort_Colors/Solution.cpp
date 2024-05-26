#include <bits/stdc++.h>

class Solution {
public:
    void sortColors(std::vector<int>& nums) {
        int min = nums[0];
        for(int i = 0; i < nums.size(); i++){
            for(int j = i+1; j < nums.size(); j++){
                if(nums[i] > nums[j])
                    std::swap(nums[i], nums[j]);
            }
        }
        for(int x : nums)
            std::cout << x <<' ';
    }
};

int main(){
    Solution s;
    std::vector<int> nums = {2,0,2,1,1,0};
    s.sortColors(nums);
    return 0;
}
