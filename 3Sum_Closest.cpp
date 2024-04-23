#include <bits/stdc++.h>
#include <vector>
class Solution {
public:
    int threeSumClosest(std::vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int diff=INT_MAX;
        int ans;
        for(int i = 0; i < n - 2; i++){
            int left = i + 1; int right = n - 1;
            while(left < right){
                if(nums[i] + nums[left] + nums[right] == target)
                    return target;
                if(abs(nums[i] + nums[left] + nums[right] - target) < diff){
                    diff = abs(nums[i] + nums[left] + nums[right] - target);
                    ans = nums[i] + nums[left] + nums[right];
                }
                else if(nums[i] + nums[left] + nums[right] > target)
                    right--;
                else
                    left++;
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    std::vector<int> nums = {-1,2,1,-4};
    int target = 2;
    int ans = s.threeSumClosest(nums, target);
    std::cout << ans << std::endl;
    return 0;
}
