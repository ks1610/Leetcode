#include <bits/stdc++.h>
#include <vector>
#include <string.h>

class Solution {
public:
    std::string countAndSay(int n) {
        std::string pre = "1";
        for(int i = 2; i <= n; i++)
        {
            std::string curr = "";
            int j = 0;
            while(j < pre.size())
            {
                int count = 0;
                char ch = pre[j];
                while(j < pre.size() && pre[j] == ch)
                {
                    count++;
                    j++;
                }
                curr += std::to_string(count) + ch;
            }
            pre = curr;
        }
        return pre;
    }
};


int main() {
    Solution solution;
    std::cout << solution.countAndSay(4) << std::endl;
    return 0;
}
