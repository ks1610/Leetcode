#include <bits/stdc++.h>

class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0)
            return false;
        while(n%3 == 0)
            n/=3;
        return n == 1;
    }
};

int main() {
    Solution s;
    int n = 45;
    std::cout << (s.isPowerOfThree(n) == 1) ? "True" : "False";
    return 0;
}
