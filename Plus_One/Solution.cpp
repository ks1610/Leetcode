#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> plusOne(std::vector<int>& digits) {
        int carry = 1;
        for (int i = digits.size() - 1; i >= 0; i--) {
            int sum = digits[i] + carry;
            digits[i] = sum % 10;
            carry = sum / 10;
        }
        if (carry > 0) {
            digits.insert(digits.begin(), carry);
        }
        return digits;
    }
};

int main() {
    Solution solution;
    
    // Example 1
    std::vector<int> digits1 = {1, 2, 3};
    std::vector<int> result1 = solution.plusOne(digits1);
    std::cout << "Result of adding one to {1, 2, 3}: ";
    for (int digit : result1) {
        std::cout << digit << " ";
    }
    std::cout << std::endl;

    // Example 2
    std::vector<int> digits2 = {9, 9, 9};
    std::vector<int> result2 = solution.plusOne(digits2);
    std::cout << "Result of adding one to {9, 9, 9}: ";
    for (int digit : result2) {
        std::cout << digit << " ";
    }
    std::cout << std::endl;

    // Example 3
    std::vector<int> digits3 = {4, 3, 2, 1};
    std::vector<int> result3 = solution.plusOne(digits3);
    std::cout << "Result of adding one to {4, 3, 2, 1}: ";
    for (int digit : result3) {
        std::cout << digit << " ";
    }
    std::cout << std::endl;

    return 0;
}
