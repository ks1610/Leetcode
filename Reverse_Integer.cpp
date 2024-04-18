#include <bits/stdc++.h>
#include <unordered_map> 

class Solution {
public:
    int reverse(int x) {
        int digit = 0;
        while(x){
            digit = digit * 10 + (x % 10);
            x/=10;
        }
        if(digit > INT_MAX  || digit < INT_MIN){
            return 0;  
        }
        return int(digit);
    }
};

int main(){
  Solution a;
  std::cout << a.reverse(123) << std::endl;
}
