#include<bits/stdc++.h>

class Solution {
public:
    int trailingZeroes(int n) {       
        int count = 0;
        while(n>0){
            n /= 5;
            count += n;
        }
        return count;
    }
};


int main() {
    Solution sol;

    // Test cases
    assert(sol.trailingZeroes(0) == 0);
    assert(sol.trailingZeroes(5) == 1);
    assert(sol.trailingZeroes(10) == 2);
    assert(sol.trailingZeroes(25) == 6);
    assert(sol.trailingZeroes(50) == 12);
    assert(sol.trailingZeroes(100) == 24);
    assert(sol.trailingZeroes(125) == 31);
    assert(sol.trailingZeroes(200) == 49);
    assert(sol.trailingZeroes(1000) == 249);
    
    std::cout << "All test cases passed!" << std::endl;

    return 0;
}
