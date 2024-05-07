/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    
    const numIndexMap = {};

    
    for (let i = 0; i < nums.length; i++) {
        const complement = target - nums[i];
        if (numIndexMap.hasOwnProperty(complement)) {
            return [numIndexMap[complement], i];
        }
        numIndexMap[nums[i]] = i;
    }
    // If no such pair is found, return an empty array
    return [];
};


// Example usage:
const nums = [2, 7, 11, 15];
const target = 9;
const result = twoSum(nums, target);
if (result.length === 2) {
    console.log(`Positions: ${result[0]}, ${result[1]}`);
} else {
    console.log("No pair found.");
}
