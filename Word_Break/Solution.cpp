#include <bits/stdc++.h>

class Solution {
public:
    bool wordBreak(std::string s, std::vector<std::string>& wordDict) {
        std::vector<bool> dp(s.size() + 1, false);
        dp[0] = true;

        //std::unordered_set<std::string> wordSet(wordDict.begin(), wordDict.end());

        for(int i = 1; i <= s.size(); i++){
            for(const std::string& w : wordDict){
                int start = i - w.length();
                if(start >= 0 && dp[start] && s.substr(start, w.length()) == w){
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[s.size()];
    }
};


int main(){
    Solution solution;
    std::string s = "leetcode";
    std::vector<std::string> wordDict = {"leet", "code"};
    
    if(solution.wordBreak(s, wordDict))
        std::cout<<"true\n";
    else 
        std::cout<<"false\n";
}
