#include <iostream>
#include <string>

class Solution {
public:
    bool isPalindrome(std::string s) {
        if (s.empty()) {
            return true;
        }

        std::string new_s;
        new_s.reserve(s.size()); // Reserve space to improve performance by avoiding multiple reallocations

        // Convert to lowercase and filter out non-alphanumeric characters
        for (char c : s) {
            if (std::isalnum(static_cast<unsigned char>(c))) {
                new_s += std::tolower(static_cast<unsigned char>(c));
            }
        }

        // If the new string is empty after filtering, it's not a palindrome
        if (new_s.empty()) {
            return false;
        }

        // Check if the filtered and lowercase string is a palindrome
        int left = 0;
        int right = new_s.size() - 1;

        while (left < right) {
            if (new_s[left] != new_s[right]) {
                return false;
            }
            left++;
            right--;
        }

        return true;
    }
};

int main() {
    Solution solution;

    std::string input1 = "A man, a plan, a canal: Panama";
    std::string input2 = "race a car";
    std::string input3 = "";
    std::string input4 = " ";
    
    std::cout << "Input: \"" << input1 << "\" => " << (solution.isPalindrome(input1)? "Palindrome":"Not a palindrome") << std::endl;
    std::cout << "Input: \"" << input2 << "\" => " << (solution.isPalindrome(input2)? "Palindrome":"Not a palindrome") << std::endl;
    std::cout << "Input: \"" << input3 << "\" => " << (solution.isPalindrome(input3)? "Palindrome":"Not a palindrome") << std::endl;
    std::cout << "Input: \"" << input4 << "\" => " << (solution.isPalindrome(input4)? "Palindrome":"Not a palindrome") << std::endl;
    
    
    return 0;
}
