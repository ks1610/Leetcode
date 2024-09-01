#include <bits/stdc++.h>

class Solution {
public:
    bool isHappy(int n) {
        int x, a;
        while(n > 9){
            x = 0;
            while(n != 0){
                a = n % 10;
                n/=10;
                x += pow(a,2);
            }
            n = x;
        }
        if(n == 1 || n == 7)
            return true;
        return false;
    }
};

int main() {
    Solution s;
    int n;
    std::cout<<"Type your numer: ";
    std::cin>>n;
    std::cout << (s.isHappy(n) ? "This is the Happy number" : "This is not the Happy number");
    return 0;
}
