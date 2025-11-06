#include <bits/stdc++.h>

class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        std::vector<int> ans(nums.size(), 1);
        int l = 1;
        for(int i = 0; i < nums.size(); i++){
            ans[i] *= l; 
            l *= nums[i];
        }
        int r = 1;
        for(int i = nums.size() - 1; i >= 0; i--){
            ans[i] *= r;
            r *= nums[i];
        }
        
        return ans;
    }
};

int main() {
    Solution sol;

    std::vector<int> nums = {-1,1,0,-3,3};
    std::vector<int> result = sol.productExceptSelf(nums);

    std::cout << "Result: ";
    for (int val : result)
        std::cout << val << " ";
    std::cout << std::endl;

    return 0;
}
