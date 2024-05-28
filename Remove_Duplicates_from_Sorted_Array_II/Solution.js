/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function(nums) {
    let j = 1;
    for (let i = 1; i < nums.length; i++) {
        if (j == 1 || nums[i] != nums[j - 2]) {
            nums[j++] = nums[i];
        }
    }
    return j;
};

// Test the function with a sample input
let nums = [1, 1, 1, 2, 2, 3, 3, 4, 4, 4, 5];

console.log("Original array:", nums);

let newLength = removeDuplicates(nums);

console.log("Array after removing duplicates:", nums.slice(0, newLength));
console.log("New length:", newLength);
