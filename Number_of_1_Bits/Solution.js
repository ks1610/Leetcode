/**
 * @param {number} n
 * @return {number}
 */
var hammingWeight = function(n) {
    let count = 0; // Initialize the count of 1 bits to 0
    
    for (let i = 0; i < 32; i++) {
        // Check if the i-th bit of n is 1
        // (n >> i) performs a bitwise right shift on n by i bits
        // & 1 isolates the least significant bit of the result
        if ((n >> i) & 1) {
            count += 1; // Increment count if the i-th bit is 1
        }
    }

    return count; // Return the total count of 1 bits
};

// Test cases
console.log(hammingWeight(0b00000000000000000000000000000001)); // Expected: 1
console.log(hammingWeight(0b00000000000000000000000000001111)); // Expected: 4
console.log(hammingWeight(0b11111111111111111111111111111111)); // Expected: 32
console.log(hammingWeight(0b00000000000000000000000000000000)); // Expected: 0
console.log(hammingWeight(0b01010101010101010101010101010101)); // Expected: 16
console.log(hammingWeight(0b10101000000011110000111100000000)); // Expected: 12
console.log(hammingWeight(0xFFFFFFFF)); // Expected: 32
console.log(hammingWeight(0)); // Expected: 0
console.log(hammingWeight(0b10000000000000000000000000000000)); // Expected: 1
console.log(hammingWeight(0b11011010101100110010101001011001)); // Expected: 16
