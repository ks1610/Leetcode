#include <bits/stdc++.h>

class Solution {
public:
    int pivotIndex(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<long long> prefix(n+5, 0);

        for (int i = 1; i <= n; i++) {
            prefix[i] = prefix[i-1] + nums[i-1];
        }

        long long total = prefix[n];

        for (int i = 0; i < n; i++) {
            long long left = prefix[i];
            long long right = total - prefix[i+1];
            if (left == right) return i;
        }
        return -1;
    }
};


int main() {
     Solution s;
     std::vector<int> nums = {1, 2, 3};
     std::cout<<s.pivotIndex(nums);
     return 0;
}
