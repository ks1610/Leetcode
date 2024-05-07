#include <bits/stdc++.h>
#include <unordered_map> 

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> num;
        
        for(int i = 0; i < nums.size(); i++) {
        
            int complement = target - nums[i];
        
            if(num.count(complement)){
                return{num[complement], i};
            }
        
            num[nums[i]] = i;
        }

        return {};
    }
};

int main(){
   std::vector<int> nums = {2, 7, 11, 15};
   int target = 9;
   Solution s;
   std::vector<int> result = s.twoSum(nums, target);
   for(int i = 0; i < result.size(); i++){
       std::cout << result[i] << " ";
   }
}
