#include <bits/stdc++.h>

class Solution {
public:
    void bt(std::vector<int>& can, int total, std::vector<int>& com,  std::vector<std::vector<int>>& re, int pos){
        if(total == 0){
            re.push_back(com);
            return;
        }
        if(total < 0)
            return;
        for(int i = pos; i < can.size(); i++){
            com.push_back(can[i]);
            bt(can, total - can[i], com, re, i);
            com.pop_back();
        }
    }
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>> re;
        std::vector<int> com;
        bt(candidates, target, com, re, 0);
        return re;
    }
};


int main() {
     Solution s;
     std::vector<int> nums = {2,3,6,7};
     int target = 7;
     std::vector<std::vector<int>> result = s.combinationSum(nums, target);
     std::cout<< "Combination Sum: " <<std::endl;
     for(int i = 0; i < result.size(); i++){
        for(int j = 0; j < result[i].size(); j++)
            std::cout << result[i][j] << ' ';
        std::cout<<std::endl;
     }
     return 0;
}

