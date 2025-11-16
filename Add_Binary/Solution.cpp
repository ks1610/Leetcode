#include <bits/stdc++.h>

class Solution {
public:
    int convert(char c){
        return c == '1' ? 1 : 0;
    }

    char convert1(int n){
        return n == 1 ? '1' : '0';
    }

    std::string addBinary(std::string a, std::string b) {
        std::string results = "";
        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;

        while (i >= 0 || j >= 0 || carry) {
            int x = (i >= 0) ? convert(a[i]) : 0;
            int y = (j >= 0) ? convert(b[j]) : 0;

            int sum = x + y + carry;
            int bit = sum % 2;
            carry = sum / 2;

            results += convert1(bit);

            i--;
            j--;
        }

        std::reverse(results.begin(), results.end());
        return results;
    }
};

int main() {
    Solution sol;

    std::string a1 = "11", b1 = "1";
    std::cout << "Input: a = " << a1 << ", b = " << b1 << std::endl;
    std::cout << "Output: " << sol.addBinary(a1, b1) << std::endl;
    cout << endl;

    std::string a2 = "1010", b2 = "1011";
    std::cout << "Input: a = " << a2 << ", b = " << b2 << std::endl;
    std::cout << "Output: " << sol.addBinary(a2, b2) << std::endl;

    return 0;
}
