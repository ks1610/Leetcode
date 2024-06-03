var singleNumber = function(nums) {
    let result = 0;
    for (let i = 0; i < nums.length; i++) {
        result ^= nums[i];
    }
    return result;
};

// Main function to test the singleNumber function
function main() {
    // Test case: Example array where all numbers except one appear twice
    const nums = [2, 3, 2, 4, 4, 3, 1];

    // Calling the singleNumber function
    const uniqueNumber = singleNumber(nums);

    // Printing the result
    console.log("The single number is:", uniqueNumber);
}

// Run the main function
main();
