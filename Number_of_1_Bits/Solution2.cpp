#include <iostream>
#include <cassert>
#include <limits>

// Define the Solution class as provided
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        uint32_t mark = 1;
        for (int i = 0; i < 32; i++) { // check in range 32 bits of n 
            if (((n >> i) & mark) != 0) // assign the gight bit of n to 1 respectively
            // 1 & 1 = 1 -> if i == 1, count increasing by 1
                count++;
        }
        return count;
    }
};

// Helper function to run a test case
void runTest(uint32_t n, int expected, Solution& sol) {
    int result = sol.hammingWeight(n);
    assert(result == expected);
    std::cout << "Test passed for n = " << n << " with result " << result << std::endl;
}

int main() {
    Solution sol;

    // Test case 1: Single bit set
    runTest(0b00000000000000000000000000000001, 1, sol); // Expected: 1

    // Test case 2: Multiple bits set
    runTest(0b00000000000000000000000000001111, 4, sol); // Expected: 4

    // Test case 3: All bits set
    runTest(0b11111111111111111111111111111111, 32, sol); // Expected: 32

    // Test case 4: No bits set
    runTest(0b00000000000000000000000000000000, 0, sol); // Expected: 0

    // Test case 5: Alternate bits set
    runTest(0b01010101010101010101010101010101, 16, sol); // Expected: 16

    // Test case 6: Random bits set
    runTest(0b10101000000011110000111100000000, 12, sol); // Expected: 12

    // Test case 7: Edge case - maximum value for uint32_t
    runTest(std::numeric_limits<uint32_t>::max(), 32, sol); // Expected: 32

    // Test case 8: Edge case - minimum value for uint32_t (0)
    runTest(0, 0, sol); // Expected: 0

    // Test case 9: Power of 2 (only one bit set)
    runTest(0b10000000000000000000000000000000, 1, sol); // Expected: 1

    // Test case 10: Complex pattern
    runTest(0b11011010101100110010101001011001, 16, sol); // Expected: 16

    std::cout << "All tests passed!" << std::endl;

    return 0;
}
