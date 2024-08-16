class Solution:
    def hammingWeight(self, n):
        """
        :type n: int
        :rtype: int
        """
        count = 0
        for i in range(32):
            # Line 8: Check if the i-th bit of n is set to 1
            # (n >> i) performs a bitwise right shift on n by i bits
            # & 1 isolates the least significant bit of the shifted result
            # ((n >> i) & 1) will be 1 if the i-th bit was originally 1, otherwise 0
            if ((n >> i) & 1) == 1:
                # Line 9: Increment the count if the i-th bit is 1
                count += 1
        # Line 10: Return the total count of 1 bits
        return count

def run_test(n, expected, sol):
    result = sol.hammingWeight(n)
    assert result == expected, f"Test failed for n = {n}. Expected {expected}, got {result}"
    print(f"Test passed for n = {n} with result {result}")

def main():
    sol = Solution()

    # Test case 1: Single bit set
    run_test(0b00000000000000000000000000000001, 1, sol)  # Expected: 1

    # Test case 2: Multiple bits set
    run_test(0b00000000000000000000000000001111, 4, sol)  # Expected: 4

    # Test case 3: All bits set
    run_test(0b11111111111111111111111111111111, 32, sol)  # Expected: 32

    # Test case 4: No bits set
    run_test(0b00000000000000000000000000000000, 0, sol)  # Expected: 0

    # Test case 5: Alternate bits set
    run_test(0b01010101010101010101010101010101, 16, sol)  # Expected: 16

    # Test case 6: Random bits set
    run_test(0b10101000000011110000111100000000, 12, sol)  # Expected: 12

    # Test case 7: Edge case - maximum value for uint32_t
    run_test(0xFFFFFFFF, 32, sol)  # Expected: 32

    # Test case 8: Edge case - minimum value for uint32_t (0)
    run_test(0, 0, sol)  # Expected: 0

    # Test case 9: Power of 2 (only one bit set)
    run_test(0b10000000000000000000000000000000, 1, sol)  # Expected: 1

    # Test case 10: Complex pattern
    run_test(0b11011010101100110010101001011001, 16, sol)  # Expected: 16

    print("All tests passed!")

if __name__ == "__main__":
    main()
