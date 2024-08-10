/**
 * @param {number[]} numbers
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(numbers, target) {
    let left = 0;
    let right = numbers.length - 1;
    while(left < right){
        if(numbers[left] + numbers[right] === target)
            return [left+1, right+1]
        else if(numbers[left] + numbers[right] < target)
            left++;
        else 
            right--;
    }
};

function testTwoSum() {
    // Test case 1: Simple case
    let numbers1 = [2, 7, 11, 15];
    let target1 = 9;
    let expected1 = [1, 2];
    let result1 = twoSum(numbers1, target1);
    console.assert(JSON.stringify(result1) === JSON.stringify(expected1), `Test case 1 failed: expected ${expected1}, got ${result1}`);

    // Test case 2: Negative numbers
    let numbers2 = [-3, -2, -1, 0, 1, 2, 3];
    let target2 = 0;
    let expected2 = [3, 6];
    let result2 = twoSum(numbers2, target2);
    console.assert(JSON.stringify(result2) === JSON.stringify(expected2), `Test case 2 failed: expected ${expected2}, got ${result2}`);

    // Test case 3: Single solution at the beginning
    let numbers3 = [1, 2, 3, 4, 4];
    let target3 = 8;
    let expected3 = [4, 5];
    let result3 = twoSum(numbers3, target3);
    console.assert(JSON.stringify(result3) === JSON.stringify(expected3), `Test case 3 failed: expected ${expected3}, got ${result3}`);

    // Test case 4: All negative numbers
    let numbers4 = [-10, -7, -3, -1];
    let target4 = -8;
    let expected4 = [2, 4];
    let result4 = twoSum(numbers4, target4);
    console.assert(JSON.stringify(result4) === JSON.stringify(expected4), `Test case 4 failed: expected ${expected4}, got ${result4}`);

    // Test case 5: Target in the middle of the list
    let numbers5 = [1, 2, 3, 7, 11];
    let target5 = 9;
    let expected5 = [2, 4];
    let result5 = twoSum(numbers5, target5);
    console.assert(JSON.stringify(result5) === JSON.stringify(expected5), `Test case 5 failed: expected ${expected5}, got ${result5}`);

    // Test case 6: Minimal case
    let numbers6 = [2, 7];
    let target6 = 9;
    let expected6 = [1, 2];
    let result6 = twoSum(numbers6, target6);
    console.assert(JSON.stringify(result6) === JSON.stringify(expected6), `Test case 6 failed: expected ${expected6}, got ${result6}`);

    console.log("All test cases passed!");
}

// Run the test
testTwoSum();
