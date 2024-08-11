#include <bits/stdc++.h>

class Solution {
public:
    int findPeakElement(std::vector<int>& number) {
        int found = 0; 
        for (int i = 1; i < number.size(); i++) {  // Start the loop from 1 to compare with the previous element
            if (number[i] > number[i - 1])
                found = i;  // Update 'found' with the current index
        }
        return found;
    }
};

int main() {
    Solution solution;
    
    std::vector<int> test1 = {1, 2, 3, 1};
    std::vector<int> test2 = {1, 2, 1, 3, 5, 6, 4};
    std::vector<int> test3 = {1, 3, 20, 4, 1, 0};
    std::vector<int> test4 = {10, 20, 30, 40, 50};
    std::vector<int> test5 = {50, 40, 30, 20, 10};

    std::cout << "Test 1 Peak Index: " << solution.findPeakElement(test1) << std::endl;  // Expected: 2
    std::cout << "Test 2 Peak Index: " << solution.findPeakElement(test2) << std::endl;  // Expected: 5
    std::cout << "Test 3 Peak Index: " << solution.findPeakElement(test3) << std::endl;  // Expected: 2
    std::cout << "Test 4 Peak Index: " << solution.findPeakElement(test4) << std::endl;  // Expected: 4
    std::cout << "Test 5 Peak Index: " << solution.findPeakElement(test5) << std::endl;  // Expected: 0

    return 0;
}
