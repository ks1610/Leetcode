#include <iostream>
#include <vector>

class Solution {
public:
    void Insertion_Sort(std::vector<int>& num) {
        int key, i, j;
        for (i = 1; i < num.size(); i++) {
            key = num[i];
            j = i - 1;
            while (j >= 0 && num[j] > key) {
                num[j + 1] = num[j];
                j--;
            }
            num[j + 1] = key;
        }
    }

    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        for (int j = 0, i = m; j < n; j++) {
            nums1[i] = nums2[j];
            i++;
        }        
        Insertion_Sort(nums1);
    }
};

int main() {
    std::vector<int> nums1 = {1, 2, 3, 0, 0, 0}; // Example nums1 with enough space for nums2
    int m = 3; // Number of initial valid elements in nums1
    std::vector<int> nums2 = {2, 5, 6}; // Example nums2
    int n = 3; // Number of elements in nums2

    Solution solution;
    solution.merge(nums1, m, nums2, n);

    // Print the result
    std::cout << "Merged array: ";
    for (int num : nums1) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
