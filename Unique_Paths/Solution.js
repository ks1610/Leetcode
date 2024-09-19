/**
 * @param {number} m
 * @param {number} n
 * @return {number}
 */
var uniquePaths = function(m, n) {
    let result = 1;
    
    let k = Math.min(m - 1, n - 1)
    
    for(let i = 1; i <= k; i++)
        result = result*(m + n - 2 - i + 1) / i

    return result 
};

function test_uniquePaths() {
    // Test cases
    console.assert(uniquePaths(3, 7) === 28, "Test Case 1 Failed");
    console.assert(uniquePaths(3, 2) === 3, "Test Case 2 Failed");
    console.assert(uniquePaths(7, 3) === 28, "Test Case 3 Failed");
    console.assert(uniquePaths(3, 3) === 6, "Test Case 4 Failed");
    
    console.log("All test cases passed!");
}

test_uniquePaths();
