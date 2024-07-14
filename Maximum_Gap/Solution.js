/**
 * @param {number[]} nums
 * @return {number}
 */
var maximumGap = function(nums) {
    if (nums.length < 2) return 0;
    let Max_Gap = 0;

    nums
        .sort((a, b) => a - b)
        .forEach((num, idx) => {
            if (!nums[idx + 1]) return Max_Gap;
            if (Math.abs(nums[idx] - nums[idx + 1]) > Max_Gap) {
                Max_Gap = Math.abs(nums[idx] - nums[idx + 1]);
            }
        });

    return Max_Gap;
};

// Example inputs and outputs
console.log(maximumGap([3, 6, 9, 1]));       // Output: 3
console.log(maximumGap([10]));               // Output: 0
console.log(maximumGap([10, 9, 8, 7]));      // Output: 1
console.log(maximumGap([1, 10000000]));      // Output: 9999999
console.log(maximumGap([1, 2, 3, 4, 5]));    // Output: 1
