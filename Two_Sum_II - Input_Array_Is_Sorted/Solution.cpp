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

void test_two_sum() {
    Solution solution;

    // Test case 1: Simple case
    std::vector<int> numbers1 = {2, 7, 11, 15};
    int target1 = 9;
    std::vector<int> expected1 = {1, 2};
    assert(solution.twoSum(numbers1, target1) == expected1);

    // Test case 2: Negative numbers
    std::vector<int> numbers2 = {-3, -2, -1, 0, 1, 2, 3};
    int target2 = 0;
    std::vector<int> expected2 = {3, 6};
    assert(solution.twoSum(numbers2, target2) == expected2);

    // Test case 3: Single solution at the beginning
    std::vector<int> numbers3 = {1, 2, 3, 4, 4};
    int target3 = 8;
    std::vector<int> expected3 = {4, 5};
    assert(solution.twoSum(numbers3, target3) == expected3);

    // Test case 4: All negative numbers
    std::vector<int> numbers4 = {-10, -7, -3, -1};
    int target4 = -8;
    std::vector<int> expected4 = {2, 4};
    assert(solution.twoSum(numbers4, target4) == expected4);

    // Test case 5: Target in the middle of the list
    std::vector<int> numbers5 = {1, 2, 3, 7, 11};
    int target5 = 9;
    std::vector<int> expected5 = {2, 4};
    assert(solution.twoSum(numbers5, target5) == expected5);

    // Test case 6: Minimal case
    std::vector<int> numbers6 = {2, 7};
    int target6 = 9;
    std::vector<int> expected6 = {1, 2};
    assert(solution.twoSum(numbers6, target6) == expected6);

    std::cout << "All test cases passed!" << std::endl;
}

int main() {
    test_two_sum();
    return 0;
}
