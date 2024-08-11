/**
 * @param {number[]} nums
 * @return {number}
 */
var findPeakElement = function(nums) {
    if (nums.length === 1) return 0;
    if (nums[0] > nums[1]) return 0;
    if (nums[nums.length - 1] > nums[nums.length - 2]) return nums.length - 1;

    let left = 0, right = nums.length - 1;
    
    while (left <= right) {
        let mid = Math.floor(left + (right - left) / 2);
        
        if (mid > 0 && mid < nums.length - 1) {
            if (nums[mid] > nums[mid + 1] && nums[mid] > nums[mid - 1]) {
                return mid;
            } else if (nums[mid] > nums[mid + 1]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        } else if (mid === 0) {
            if (nums[mid] > nums[mid + 1]) {
                return mid;
            } else {
                return mid + 1;
            }
        } else if (mid === nums.length - 1) {
            if (nums[mid] > nums[mid - 1]) {
                return mid;
            } else {
                return mid - 1;
            }
        }
    }
    
    return -1; // This should never be reached if the input is valid
};

// Test cases
function testFindPeakElement() {
    const testCases = [
        { input: [1, 2, 3, 1], expected: 2 },
        { input: [1, 2, 1, 3, 5, 6, 4], expected: 5 },
        { input: [1, 3, 20, 4, 1, 0], expected: 2 },
        { input: [10, 20, 30, 40, 50], expected: 4 },
        { input: [50, 40, 30, 20, 10], expected: 0 },
        { input: [10], expected: 0 },
        { input: [1, 2], expected: 1 },
        { input: [1, 2, 3, 2, 4, 3], expected: 2 },
        { input: [10, 20, 30, 40, 30, 20, 10], expected: 3 }
    ];
    
    testCases.forEach((testCase, index) => {
        const result = findPeakElement(testCase.input);
        console.log(`Test Case ${index + 1} - Input: [${testCase.input}]`);
        console.log(`Expected: ${testCase.expected}, Got: ${result}`);
        console.log(result === testCase.expected ? 'Pass' : 'Fail');
        console.log('---');
    });
}

// Run the tests
testFindPeakElement();
