/**
 * @param {number[]} nums
 * @return {number}
 */
var longestConsecutive = function(nums) {
    const numSet = new Set(nums);
    let longest = 0;
    
    for (let num of numSet) {
        // Only start counting if `num - 1` is not in the set (meaning `num` is the start of a sequence)
        if (!numSet.has(num - 1)) {
            let currentNum = num;
            let currentStreak = 1;

            // Continue counting consecutive numbers
            while (numSet.has(currentNum + 1)) {
                currentNum += 1;
                currentStreak += 1;
            }

            // Update the longest streak found
            longest = Math.max(longest, currentStreak);
        }
    }

    return longest;
};

// Example usage
const nums = [100, 4, 200, 1, 3, 2];
console.log("Longest consecutive sequence length:", longestConsecutive(nums)); // Output: 4
