#include <bits/stdc++.h>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        std::vector<std::vector<int>> ans;
        int n = nums.size();
        
        for(int i = 0; i < n ; i++)
        {
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            for(int j = i + 1 ; j < n; j++)
            {
                if(j > (i + 1) && nums[j] == nums[j - 1]) continue;
                int left = j + 1;
                int right = n - 1;

                while(left < right)
                {
                    //long long sum = nums[i] + nums[j] + nums[left] + nums[right];
                    long long sum = nums[i];
                    sum += nums[j];
                    sum += nums[left];
                    sum += nums[right];

                    if(sum == target)
                    {
                        ans.push_back({nums[i] , nums[j] , nums[left] , nums[right]});
                        left++;
                        right--;
                        while(left < right && nums[left] == nums[left - 1])
                            left++;
                        while(left < right && nums[right] == nums[right + 1])
                            right--;
                    }
                    else if(sum > target)
                        right--;
                    else 
                        left++;
                }
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    std::vector<int> nums = {1,0,-1,0,-2,2};
    int target = 0;
    std::vector<std::vector<int>> ans = s.fourSum(nums,target);
    for(const auto it : ans){
        for(int num : it)
            std::cout << num << ' ';
        std::cout << std::endl;
    }
    return 0;
}
