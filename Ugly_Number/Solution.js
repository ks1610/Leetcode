/**
 * @param {number} n
 * @return {boolean}
 */
var isUgly = function(n) {
    if (n <= 0)
        return false;
    while (n % 2 === 0)
        n /= 2;
    while (n % 3 === 0)
        n /= 3;
    while (n % 5 === 0)
        n /= 5;
    return n === 1;
};

// ==== Testing ====
const nums = [6, 8, 14, 1, 0, -5];
for (let n of nums) {
    console.log(`${n} -> ${isUgly(n)}`);
}
