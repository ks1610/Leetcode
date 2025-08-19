#include <iostream>
using namespace std;

class Solution {
public:
    bool isUgly(int n) {
        if(n <= 0)
            return false;
        while(n % 2 == 0)
            n /= 2;
        while(n % 3 == 0)
            n /= 3;
        while(n % 5 == 0)
            n /= 5;
        return n == 1;
    }
};

int main() {
    Solution sol;
    int nums[] = {6, 8, 14, 1, 0, -5};

    for(int n : nums) {
        cout << n << " -> " << (sol.isUgly(n) ? "True" : "False") << endl;
    }

    return 0;
}
