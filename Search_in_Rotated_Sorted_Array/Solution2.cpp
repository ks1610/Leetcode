#include<bits/stdc++.h>

class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto fi = find(nums.begin(), nums.end(), target);
        return (fi != nums.end()) ? distance(nums.begin(), fi) : -1;
    }
};
