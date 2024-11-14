/*You are a professional robber planning to rob houses along a street. 
Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected 
and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

class Solution {
public:
    int rob(std::vector<int>& nums) {
        int n = nums.size();
        
        if(n==1) 
            return nums[0];
        
        std::vector<int> dp(n);
        dp[0] = nums[0];
        dp[1] = std::max(nums[0], nums[1]);
        
        for(int i = 2; i < n; i++){
            dp[i] = std::max(dp[i-1], dp[i-2] + nums[i]);
        }
        
        return dp[n - 1];
    }
};

int main(){
    Solution s;
    std::vector<int> num = {2,1,1,2};
    int result = s.rob(num);
    std::cout << result;
    return 0;
}
