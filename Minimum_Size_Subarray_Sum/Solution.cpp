#include <bits/stdc++.h>

class Solution {
public:
    int minSubArrayLen(int target, std::vector<int>& nums) {
        long long minval = pow(10,8);
        long long l = 0;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            while(sum >= target){
                if(i - l + 1 <= minval)
                    minval = i - l + 1;
                sum -= nums[l];
                l++;
            }
        }
        return (minval == pow(10,8)) ? 0 : minval;
    }
};

int main() {
    Solution sol;
    int target;
    int n;
    std::cout << "Enter target: ";
    std::cin >> target;
    std::cout << "Enter number of elements: ";
    std::cin >> n;
    
    std::vector<int> nums(n);
    std::cout << "Enter elements: ";
    for(int i = 0; i < n; ++i) {
        std::cin >> nums[i];
    }
    // for(int i = 0; i < n; ++i) {
    //     std::cout << nums[i];
    // }

    int result = sol.minSubArrayLen(target, nums);
    std::cout << "Result: " << result << std::endl;

    return 0;
}
