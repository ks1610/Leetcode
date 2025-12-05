//Find the Duplicate Number 
#include <bits/stdc++.h>


class Solution {
public:
    int findDuplicate(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int found = 0;
        int size = nums.size()-1;
        for(int i = 0; i < size; i++){
            //std::cout<<nums[i]<<" ";
            if(nums[i] == nums[i+1])
                found = nums[i];
        }
        return found;
    }
};

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    Solution s;
    std::vector<int> nums = {1,1};
    std::sort(nums.begin(), nums.end());
    for(auto x : nums)
        std::cout<<x<<" ";
    std::cout << s.findDuplicate(nums) << "\n";
    return 0;

} 
