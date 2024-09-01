/**
 * @param {number} n
 * @return {boolean}
 */
var isHappy = function(n) {
    while (n > 9) {
        let x = 0;
        while (n != 0) {
            let a = n % 10;
            n = Math.floor(n / 10);
            x += a * a;
        }
        n = x;
    }
    if (n === 1 || n === 7)
        return true;
    return false;
};

function testIsHappy() {
    // Test cases
    let tests = [
        { input: 19, expected: true },
        { input: 7, expected: true },
        { input: 2, expected: false },
        { input: 1, expected: true },
        { input: 1111111, expected: true },
        { input: 4, expected: false }
    ];

    // Run tests
    for (let i = 0; i < tests.length; i++) {
        let result = isHappy(tests[i].input);
        if (result !== tests[i].expected) {
            console.log(`Test case ${i + 1} failed: input ${tests[i].input}, expected ${tests[i].expected}, got ${result}`);
        } else {
            console.log(`Test case ${i + 1} passed.`);
        }
    }
}

// Run the tests
testIsHappy();
