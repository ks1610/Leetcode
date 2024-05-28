/**
 * @param {string} s
 * @param {string} t
 * @param {number} maxCost
 * @return {number}
 */
var equalSubstring = function(s, t, maxCost) {
    let l = 0, cost = 0, result = 0;

    for(let i = 0; i < s.length; i++) {
        cost += Math.abs(s.charCodeAt(i) - t.charCodeAt(i));

        while(cost > maxCost) {
            cost -= Math.abs(s.charCodeAt(l) - t.charCodeAt(l));
            l++;
        }
        result = Math.max(result, i - l + 1);
    }
    return result;
};

// Main test function
function main() {
    // Test case 1
    let s1 = "abcd";
    let t1 = "bcdf";
    let maxCost1 = 3;
    let expected1 = 3;
    console.assert(equalSubstring(s1, t1, maxCost1) === expected1, `Test case 1 failed`);

    // Test case 2
    let s2 = "abcd";
    let t2 = "cdef";
    let maxCost2 = 3;
    let expected2 = 1;
    console.assert(equalSubstring(s2, t2, maxCost2) === expected2, `Test case 2 failed`);

    // Test case 3
    let s3 = "abcd";
    let t3 = "acde";
    let maxCost3 = 0;
    let expected3 = 1;
    console.assert(equalSubstring(s3, t3, maxCost3) === expected3, `Test case 3 failed`);

    // Test case 4
    let s4 = "krrgw";
    let t4 = "zjxss";
    let maxCost4 = 19;
    let expected4 = 2;
    console.assert(equalSubstring(s4, t4, maxCost4) === expected4, `Test case 4 failed`);

    // Test case 5
    let s5 = "abcdxyz";
    let t5 = "abcdefg";
    let maxCost5 = 5;
    let expected5 = 4;
    console.assert(equalSubstring(s5, t5, maxCost5) === expected5, `Test case 5 failed`);

    console.log("All test cases passed!");
}

// Run the test function
main();
