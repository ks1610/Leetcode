#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

/*Example 1:
Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.

Example 2:
Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
 */

class Solution {
public:
    int maxProduct(std::vector<int>& nums) {
        int ans = INT_MIN;
        int pre = 0;
        int suf = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(pre == 0)
                pre = 1;
            if(suf == 0)
                suf = 1;
            pre = pre * nums[i];
            suf = suf * nums[n - i - 1];
            ans = std::max(ans, std::max(pre, suf));
        }
        return ans;
    }
};

int main(){
    Solution s, s1;
    std::vector<int> num1 = {2,3,-2,4};
    std::vector<int> num2 = {-2,0,-1};
    int result, result1;
    result = s.maxProduct(num1);
    result1 = s1.maxProduct(num2);
    std::cout<<"Maximum Product Subarray Of Num1: "<< result<<std::endl;
    std::cout<<"Maximum Product Subarray Of Num2: "<< result1<<std::endl;
}
