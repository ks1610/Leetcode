#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsum = nums[0];
        int current = nums[0];

        for(int i = 1; i < nums.size(); i++){
            current = max(nums[i], nums[i] + current);
            maxsum = max(maxsum, current);
        }

        return maxsum;
    }
};

int main() {
    Solution solution;
    vector<int> nums = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
    int result = solution.maxSubArray(nums);
    cout << "Maximum subarray sum: " << result << endl;
    return 0;
}
