#include <bits/stdc++.h>
#include <string>

class Solution{
    public:

        //convert decimal number to binary -> can ignore this function
        unsigned int bin_convert(unsigned int n ){
            unsigned int binary = 0;
            unsigned int place = 1;

            while(n > 0){
                unsigned int remainder = n % 2;
                binary += remainder * place;
                n /= 2;
                place *= 10;
            }

            return binary;
        }

        //convert decimal number to binary then convert to string type
        std::string str_convert(unsigned int n ){
            std::string binary = "";
            unsigned int place = 1;
            while(n > 0){
                unsigned int remainder = n % 2;
                binary += remainder + '0';
                n /= 2;
            }
            std::reverse(binary.begin(), binary.end());

            return binary;
        }

        //count the number "1" in a binary string
        unsigned int hammingWeight(unsigned int n){
            std::string s = str_convert(n);
            int count = 0;
            for(int i = 0 ; i < s.size(); i++){
                if(s[i] == '1')
                count++;
            }
            return count;
        }
};

void run_test(unsigned int n, const std::string& expected_binary, unsigned int expected_hamming_weight) {
    Solution solution;
    std::string binary = solution.str_convert(n);
    unsigned int hamming_weight = solution.hammingWeight(n);

    std::cout << "Test for n = " << n << ":\n";
    std::cout << "Expected Binary: " << expected_binary << ", Got: " << binary << "\n";
    std::cout << "Expected Hamming Weight: " << expected_hamming_weight << ", Got: " << hamming_weight << "\n";

    if (binary == expected_binary && hamming_weight == expected_hamming_weight) {
        std::cout << "Test passed!\n\n";
    } else {
        std::cout << "Test failed!\n\n";
    }
}


int main() {

    // Test cases
    run_test(0, "0", 0);
    run_test(10, "1010", 2);
    run_test(15, "1111", 4);
    run_test(1, "1", 1);
    run_test(1024, "10000000000", 1);
    run_test(255, "11111111", 8);
    run_test(4294967295, "11111111111111111111111111111111", 32);

    return 0;
}
