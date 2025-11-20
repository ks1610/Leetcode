#include <bits/stdc++.h>

class Solution {
public:
    std::vector<int> majorityElement(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        std::vector<int> found;
        int count = 1;
        int n = nums.size();
        if(n <= 2){
            for(int i = 0; i <= n-1; i++){
                found.push_back(nums[i]);
            }
        }
        else{
            for(int i = 1; i <= n-1; i++){
                if(nums[i] == nums[i-1]){
                    count+=1;
                }
                if(count > nums.size()/3){
                    found.push_back(nums[i]);
                    count = 0;
                }
                if(nums[i] != nums[i-1])
                {
                    count = 1;
                }
            }
        }
        if(found.size()){
            std::vector<int>final;
            for(int x = 0; x < found.size() - 1; x++){
                if(found[x] == found[x+1])
                    found.erase(found.begin());
            }
        }
        return found;
    }
};

int main() {
    Solution sol;

    std::vector<int> nums = {3,3,3,3,3,3,3};
    //std::vector<int> nums = {2,2,2,3,3};

    std::vector<int> result = sol.majorityElement(nums);

    std::cout << "Majority elements (> n/3): ";
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
