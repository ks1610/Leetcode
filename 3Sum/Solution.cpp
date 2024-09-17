#include <bits/stdc++.h>
#include <vector>
class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        sort(nums.begin(), nums.end());
        std::set<std::vector<int>> st;
        int sum, left, right;
        for(int i = 0; i < nums.size(); i++){
            left = i + 1;
            right = nums.size() - 1;
            while(left < right){
                sum = nums[i] + nums[left] + nums[right];
                if(sum == 0){
                    st.insert({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                }
                else if(sum < 0){
                    left++;
                }
                else right--;
            }
        }
        std::vector<std::vector<int>> output;
        for(auto triplets : st)
            output.push_back(triplets);
        return output;
    }
};
int main(){
    Solution s;
    std::vector<int> num = {-1,0,1,2,-1,-4};
    std::vector<std::vector<int>> output = s.threeSum(num);

    for (const auto& triplet : output) {
        std::cout << "[ ";
        for (int num : triplet) {
            std::cout << num << " ";
        }
        std::cout << "]" << std::endl;
    }

    return 0;
}
