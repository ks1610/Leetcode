/**
 * @param {number[]} nums1
 * @param {number} m
 * @param {number[]} nums2
 * @param {number} n
 * @return {void} Do not return anything, modify nums1 in-place instead.
 */

var Insertion_Sort = function(number) {
    let key, i, j;
    for (i = 1; i < number.length; i++) {
        key = number[i];
        j = i - 1;
        while (j >= 0 && number[j] > key) {
            number[j + 1] = number[j];
            j--;
        }
        number[j + 1] = key;
    }
}

var merge = function(nums1, m, nums2, n) {
    for (let j = 0, i = m; j < n; j++) {
        nums1[i] = nums2[j];
        i++;
    }
    Insertion_Sort(nums1);
};

// Example usage
let nums1 = [1, 2, 3, 0, 0, 0]; // nums1 with enough space for nums2
let m = 3; // Number of initial valid elements in nums1
let nums2 = [2, 5, 6]; // nums2
let n = 3; // Number of elements in nums2

merge(nums1, m, nums2, n);

console.log("Merged array:", nums1);
