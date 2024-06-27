/**
 * @param {number} columnNumber
 * @return {string}
 */
var convertToTitle = function(columnNumber) {

    let ans = "";
    let num = columnNumber;

    while (num > 0) {
        let sur = num % 26;

        if (sur === 0) {
            sur = 26;
            num--;  // adjust the number
        }

        ans = String.fromCharCode(64 + sur) + ans;
        num = Math.floor(num / 26);  // adjust the number correctly
    }

    return ans;
};

/**
 * Function to run test cases
 * @param {number} columnNumber
 * @param {string} expected
 */
function runTest(columnNumber, expected) {
    const result = convertToTitle(columnNumber);
    console.log(`Input: ${columnNumber} -> Output: ${result} (Expected: ${expected})`);
}

// Test cases
runTest(1, "A");      // Output: "A"
runTest(26, "Z");     // Output: "Z"
runTest(27, "AA");    // Output: "AA"
runTest(28, "AB");    // Output: "AB"
runTest(52, "AZ");    // Output: "AZ"
runTest(701, "ZY");   // Output: "ZY"
runTest(702, "ZZ");   // Output: "ZZ"
runTest(703, "AAA");  // Output: "AAA"
