#include <bits/stdc++.h>

class Solution {
private:
    int binary_search(std::vector<int>& number, int left, int right, int target){
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(number[mid] == target) 
                return mid;
            else if(number[mid] < target) 
                left = mid + 1;
            else 
                right = mid - 1;
        }
        return -1;
    }
public:
    std::vector<int> twoSum(std::vector<int>& number, int target) {
        for(int i = 0; i < number.size(); i++){
            int num = target - number[i];
            int index = binary_search(number, i + 1, number.size() - 1, num);
            if(index != -1){
                return {i+1, index+1};
                return {i+1, index+1, number[i], number[index]};
            }
        }
        return {};
    }
};

int main(){
    Solution solution;
    std::vector<int> number = {2,3,4};
    int target = 6;
    std::vector<int> result = solution.twoSum(number, target);
    std::cout << "[" << result[0] << ", " << result[1]<< ", " << result[2]<< ", " << result[3]<<"]" <<std::endl;
    std::cout << "[" << result[0] << ", " << result[1]<<"]" <<std::endl;
    return 0;
}
