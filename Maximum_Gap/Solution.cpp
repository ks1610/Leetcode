#include<bits/stdc++.h>

class Solution {
public:
    int maximumGap(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        
        if(nums.size() < 2)
            return 0;

        int Max_Gap = 0;

        for(int i = 1; i < nums.size(); i++){
            int Gap = nums[i] - nums[i-1];
            Max_Gap = std::max(Max_Gap, Gap);
        }
        
        return Max_Gap;
    }
};

int main(){
    Solution new_s;
    std::vector<int> new_nums = {1, 3, 6, 9};
    std::cout << "The maximun gap is: " << new_s.maximumGap(new_nums) << std::endl;
}
