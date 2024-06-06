#include <iostream>
#include <vector>

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        /*int t = 0;
        for(int i = 0; i< nums.size(); i++){
            if(target == nums[i])
                t = 1;
        }
        if(t == 1)
            return true;
        else 
            return false;
        */

        int left = 0;
        int right = nums.size() - 1;
        std::sort(nums.begin(), nums.end());
        while(left <= right){
            int mid = left + (right - left)/2;
            if(nums[mid] == target)
                return true;
            if(nums[left] == nums[mid] && nums[right] == nums[mid]){
                left++;
                right--;
            }
            else if(nums[left] <= nums[mid]){
                if(nums[left] <= target && nums[mid] > target)
                    right = mid -1;
                else
                    left = mid + 1;
            }
            else{
                if(nums[mid] < target && nums[right] >= target)
                    left = mid + 1;
                else
                    right = mid -1;
            }
        }
        return false; 
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    
    bool result = solution.search(nums, target);
    std::cout << "Target " << target << (result ? " is" : " is not") << " in the array." << std::endl;
    
    target = 3;
    result = solution.search(nums, target);
    std::cout << "Target " << target << (result ? " is" : " is not") << " in the array." << std::endl;
    
    return 0;
}
