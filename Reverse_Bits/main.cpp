#include <bits/stdc++.h>

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t a = 0;
        for (int i = 0; i < 32; i++) {
            a <<= 1;
            a |= (n & 1);
            n >>= 1;
        }
        return a;
    }
};

int main() {
    Solution solution;

    // Example input: 00000010100101000001111010011100 (binary)
    uint32_t n = 0b00000010100101000001111010011100;

    // Call reverseBits function
    uint32_t reversed = solution.reverseBits(n);

    // Output the result in decimal
    std::cout << "Reversed bits in decimal: " << reversed << std::endl;

    return 0;
}
