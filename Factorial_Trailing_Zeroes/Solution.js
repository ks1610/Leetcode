/**
 * @param {number} n
 * @return {number}
 */
var trailingZeroes = function(n) {
    let count = 0;
    while (n > 0) {
        n = Math.floor(n / 5); // Perform integer division
        count += n;
    }
    return count;
};

function testTrailingZeroes() {
    // Test cases
    const testCases = [
        { input: 0, expected: 0 },
        { input: 5, expected: 1 },
        { input: 10, expected: 2 },
        { input: 25, expected: 6 },
        { input: 50, expected: 12 },
        { input: 100, expected: 24 },
        { input: 125, expected: 31 },
        { input: 200, expected: 49 },
        { input: 1000, expected: 249 }
    ];
    
    // Run each test case
    for (let i = 0; i < testCases.length; i++) {
        const { input, expected } = testCases[i];
        const result = trailingZeroes(input);
        if (result === expected) {
            console.log(`Test case ${i + 1} passed: trailingZeroes(${input}) = ${result}`);
        } else {
            console.error(`Test case ${i + 1} failed: trailingZeroes(${input}) = ${result}, expected ${expected}`);
        }
    }
}

// Define the trailingZeroes function (assuming you copied the corrected function here)
var trailingZeroes = function(n) {
    let count = 0;
    while (n > 0) {
        n = Math.floor(n / 5);
        count += n;
    }
    return count;
};

// Run the test function
testTrailingZeroes();
