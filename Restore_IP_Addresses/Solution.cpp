#include <bits/stdc++.h>
#include <string.h>

class Solution {
public:
    std::vector<std::string> restoreIpAddresses(std::string s) {
      std::vector<std::string> ans;
      std::string k;
        
      for(int a = 1; a <= 3; a++){
        for(int b = 1; b <= 3; b++){
            for(int c = 1; c <= 3; c++){
                for(int d = 1; d <= 3; d++){
                    if(a+b+c+d == s.length()){
                        int s1 = stoi(s.substr(0,a));
                        int s2 = stoi(s.substr(a,b));
                        int s3 = stoi(s.substr(a+b,c));
                        int s4 = stoi(s.substr(a+b+c,d));
                        k = std::to_string(s1)+"."+ std::to_string(s2)+"."+ std::to_string(s3)+"."+ std::to_string(s4);
                        if(s1<=255 && s2<=255 && s3<=255 && s4<=255){
                            if(k.length() == s.length()+3)
                                ans.push_back(k);
                        }
                    }
                }
            }
        }
      }
      return ans;
    }
};

int main() {
    std::cout<<"IP: 25525511135"<<std::endl;
    Solution s1;
    std::vector<std::string> ip1 = s1.restoreIpAddresses("25525511135");
    for(auto x : ip1)
        std::cout << x << std::endl;
    std::cout<<std::endl;

    std::cout<<"IP: 0000"<<std::endl;
    Solution s2;
    std::vector<std::string> ip2 = s2.restoreIpAddresses("0000");
    for(auto x : ip2)
        std::cout << x << std::endl;
    std::cout<<std::endl;
    
    std::cout<<"IP: 101023"<<std::endl;
    Solution s3;
    std::vector<std::string> ip3 = s3.restoreIpAddresses("101023");
    for(auto x : ip3)
        std::cout << x << std::endl;
    std::cout<<std::endl;
    
    return 0;
}
