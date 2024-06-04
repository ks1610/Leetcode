#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
        std::unordered_map<int, int> mp;
        int res = 0;

        for(auto x: nums)
            mp[x]++;
        
        for(auto a: mp)
            if(a.second == 1)
                res = a.first;
        return res;
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = {4, 1, 2, 1, 2};
    
    int result = solution.singleNumber(nums);
    
    std::cout << "The single number is: " << result << std::endl;
    
    return 0;
}
