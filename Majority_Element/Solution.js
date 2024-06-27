/**
 * @param {number[]} nums
 * @return {number}
 */
var majorityElement = function(nums) {
    let res = nums[0];
    let majority = 0;

    for (const n of nums) {
        if (majority === 0) {
            res = n;
        }
        majority += n === res ? 1 : -1;
    }

    return res;
};

// Example usage:
const nums = [2, 2, 1, 1, 1, 2, 2];
console.log(majorityElement(nums)); // Output: 2
