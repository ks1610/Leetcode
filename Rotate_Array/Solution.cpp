#include <iostream>
#include <vector>

class Solution {
public:
    void rotate(std::vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        std::reverse(nums.begin(), nums.end());
        std::reverse(nums.begin(), nums.begin()+k);
        std::reverse(nums.begin()+k, nums.end());
    }
};

int main() {
    Solution s;
    
    std::vector<int> nums1 = {1, 2, 3, 4, 5, 6, 7};
    int k1 = 3;
    s.rotate(nums1, k1);
    std::cout << "After rotating by " << k1 << ": ";
    for (int num : nums1) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    std::vector<int> nums2 = {-1, -100, 3, 99};
    int k2 = 2;
    s.rotate(nums2, k2);
    std::cout << "After rotating by " << k2 << ": ";
    for (int num : nums2) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
