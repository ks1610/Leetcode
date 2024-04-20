#include <bits/stdc++.h>

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        std::string str;

        for(int i = 0 ; i < strs[0].size(); i++){
            for(int j = 1; j < strs.size(); j++){
                if(strs[0][i] != strs[j][i]){
                    return str;
                }
            }
            str += strs[0][i];
        }
        
        return str;
    }
};

int main(){
    Solution s;
    std::vector<std::string> strs = {"flower","flow","flight"};
    std::cout << s.longestCommonPrefix(strs) << std::endl;
    return 0;
}
