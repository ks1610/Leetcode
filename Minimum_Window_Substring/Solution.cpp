#include <bits/stdc++.h>

class Solution {
public:
    std::string minWindow(std::string s, std::string t) {
      //create map vector with 128 variable and set all to 0
      std::vector<int> map(128, 0);
      //increase value of t to 1
      for(char c : t)
            map[c]++;
      int count = t.size(), begin = 0, end = 0, d = INT_MAX, head = 0;
      //moving value end
      while(end < s.size()){
          //decrease count by 1 until count = 0  
          if(map[s[end++]]-- > 0)
                count--;
          //find head and d when count is 0
          while(count == 0){
              if(end - begin < d){
                  head = begin;
                  d = end - head;
              }
              //restore count value by increasing by 1
              if(map[s[begin++]]++ == 0)
                  count++;
            }
        } 
        //Return the minimum window or empty string
        return d == INT_MAX ? "" : s.substr(head, d);
    }
};

int main() {
    Solution sol;

    // Test case 1
    std::string s1 = "ADOBECODEBANC";
    std::string t1 = "ABC";
    std::cout << "Test 1 - Expected: BANC, Output: " << sol.minWindow(s1, t1) << std::endl;

    // Test case 2
    std::string s2 = "a";
    std::string t2 = "a";
    std::cout << "Test 2 - Expected: a, Output: " << sol.minWindow(s2, t2) << std::endl;

    // Test case 3
    std::string s3 = "a";
    std::string t3 = "aa";
    std::cout << "Test 3 - Expected: \"\", Output: \"" << sol.minWindow(s3, t3) << "\"" << std::endl;

    // Test case 4
    std::string s4 = "thisisateststring";
    std::string t4 = "tist";
    std::cout << "Test 4 - Expected: tstri, Output: " << sol.minWindow(s4, t4) << std::endl;

    // Test case 5
    std::string s5 = "abcdef";
    std::string t5 = "f";
    std::cout << "Test 5 - Expected: f, Output: " << sol.minWindow(s5, t5) << std::endl;

    // Test case 6
    std::string s6 = "abcd";
    std::string t6 = "xyz";
    std::cout << "Test 6 - Expected: \"\", Output: \"" << sol.minWindow(s6, t6) << "\"" << std::endl;

    return 0;
}
