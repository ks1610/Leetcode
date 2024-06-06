/**
 * @param {number[]} nums
 * @param {number} target
 * @return {boolean}
 */
var search = function(nums, target) {
    let left = 0;
    let right = nums.length - 1;
    
    while (left <= right) {
        let mid = Math.floor((left + right) / 2);

        if (nums[mid] === target) {
            return true;
        }
        
        if (nums[mid] === nums[left]) {
            left++;
            continue;
        }
                
        if (nums[left] <= nums[mid]) {
            if (nums[left] <= target && target < nums[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        } else {
            if (nums[mid] < target && target <= nums[right]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }
    return false;
};

// Main function to test the search function
(function() {
    let solution = search;
    let nums = [4, 5, 6, 7, 0, 1, 2];
    let target = 0;
    
    let result = solution(nums, target);
    console.log("Target " + target + (result ? " is" : " is not") + " in the array.");
    
    target = 3;
    result = solution(nums, target);
    console.log("Target " + target + (result ? " is" : " is not") + " in the array.");
})();
