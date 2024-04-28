#include <bits/stdc++.h>
#include <vector>

class Solution {
public:
    int longestValidParentheses(std::string s) {
        std::stack<int>stk;
        int count = 0;
        stk.push(-1);
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '(')
                stk.push(i);
            else{
                if(stk.size() == 1)
                    stk.top() = i;
                else{
                    stk.pop();
                    count = std::max(count, i - stk.top());
                }
            }
        }
        return count;
    }
};


int main() {
    Solution solution;
    std::string parentheses = "(()()";
    int longest_valid = solution.longestValidParentheses(parentheses);
    std::cout << "Longest valid parentheses length: " << longest_valid << std::endl;
    return 0;
}
