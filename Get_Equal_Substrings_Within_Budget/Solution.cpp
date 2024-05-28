#include <iostream>
#include <string>
#include <cassert>

class Solution {
public:
    int equalSubstring(std::string s, std::string t, int maxCost) {
        int l = 0, cost = 0, result = 0;

        for(int i = 0; i < s.size(); i++){
            cost += abs(s[i] - t[i]);

            while(cost > maxCost){
                cost -= abs(s[l] - t[l]);
                l++;
            }

            result = std::max(result, i - l + 1);
        }

        return result; 
    }
};

int main() {
    Solution solution;

    // Test case 1
    std::string s1 = "abcd";
    std::string t1 = "bcdf";
    int maxCost1 = 3;
    int expected1 = 3;
    assert(solution.equalSubstring(s1, t1, maxCost1) == expected1);

    // Test case 2
    std::string s2 = "abcd";
    std::string t2 = "cdef";
    int maxCost2 = 3;
    int expected2 = 1;
    assert(solution.equalSubstring(s2, t2, maxCost2) == expected2);

    // Test case 3
    std::string s3 = "abcd";
    std::string t3 = "acde";
    int maxCost3 = 0;
    int expected3 = 1;
    assert(solution.equalSubstring(s3, t3, maxCost3) == expected3);

    // Test case 4
    std::string s4 = "krrgw";
    std::string t4 = "zjxss";
    int maxCost4 = 19;
    int expected4 = 2;
    assert(solution.equalSubstring(s4, t4, maxCost4) == expected4);

    // Test case 5
    std::string s5 = "abcdxyz";
    std::string t5 = "abcdefg";
    int maxCost5 = 5;
    int expected5 = 4;
    assert(solution.equalSubstring(s5, t5, maxCost5) == expected5);

    std::cout << "All test cases passed!" << std::endl;

    return 0;
}
