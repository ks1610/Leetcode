
#include <iostream>

class Solution {
public:
    int countPrimes(int n) {
        int count = 0;
        if (n <= 2) return 0;

        vector<bool> isPrime(n, true);
        isPrime[0] = isPrime[1] = false;

        for(int i = 2; i*i < n; i++){
            if(isPrime[i]){
                for(int j = i*i; j < n; j += i)
                    isPrime[j] = false;
            }
        }

        for(int i = 2; i< n; i++){
            if(isPrime[i])
                count++;
        }

        return count;
    }
};

void test_countPrimes() {
    Solution sol;

    // Test case 1: n = 0
    if (sol.countPrimes(0) == 0) {
        std::cout << "Test case 1 passed.\n";
    } else {
        std::cout << "Test case 1 failed.\n";
    }

    // Test case 2: n = 1
    if (sol.countPrimes(1) == 0) {
        std::cout << "Test case 2 passed.\n";
    } else {
        std::cout << "Test case 2 failed.\n";
    }

    // Test case 3: n = 2
    if (sol.countPrimes(2) == 0) {
        std::cout << "Test case 3 passed.\n";
    } else {
        std::cout << "Test case 3 failed.\n";
    }

    // Test case 4: n = 10 (Primes: 2, 3, 5, 7)
    if (sol.countPrimes(10) == 4) {
        std::cout << "Test case 4 passed.\n";
    } else {
        std::cout << "Test case 4 failed.\n";
    }

    // Test case 5: n = 100 (Primes: 25 primes below 100)
    if (sol.countPrimes(100) == 25) {
        std::cout << "Test case 5 passed.\n";
    } else {
        std::cout << "Test case 5 failed.\n";
    }

    // Test case 6: n = 5000
    if (sol.countPrimes(5000) == 669) {
        std::cout << "Test case 6 passed.\n";
    } else {
        std::cout << "Test case 6 failed.\n";
    }
}

int main() {
    test_countPrimes();
    std::cout << "Testing complete.\n";
    return 0;
}
