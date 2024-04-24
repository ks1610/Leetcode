#include <iostream>
#include <vector>

int tribonacci(int n, std::vector<int>& memo) {
    if (n == 0) {
        return 0;
    } else if (n == 1 || n == 2) {
        return 1;
    }

    // Check if the result for `n` is already computed and stored in the memoization table
    if (memo[n] != -1) {
        return memo[n];
    }

    // Compute the Tribonacci number recursively and store the result in the memoization table
    memo[n] = tribonacci(n - 1, memo) + tribonacci(n - 2, memo) + tribonacci(n - 3, memo);
    return memo[n];
}

int tribonacci(int n) {
    // Create a memoization table initialized with -1 to indicate values not computed yet
    std::vector<int> memo(n + 1, -1);
    return tribonacci(n, memo);
}

int main() {
    int n = 35;  // Compute the 35th Tribonacci number
    std::cout << "Tribonacci(" << n << ") = " << tribonacci(n) << std::endl;
    return 0;
}
