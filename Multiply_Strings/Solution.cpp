#include <bits/stdc++.h>
#include <vector>
#include <string.h>

class Solution {
private:
    void multiDigi(std::string& num1, std::string& num2, std::vector<int>& product){
        for(int i = num1.size() - 1; i >= 0; i--) {

            for(int j = num2.size() - 1; j >= 0; j--) {

                int digit1 = num1[i] - '0';
                int digit2 = num2[j] - '0';
                int multiply = digit1 * digit2;

                int sum = multiply + product[i + j + 1];
                product[i + j + 1] = sum % 10;
                product[i + j] += sum / 10;
            }
        }
    }

    std::string To_String(const std::vector<int>& product){
        std::string result = "";
        for(int i : product){
            result += std::to_string(i);
        }
        return result;
    } 

    std::string removeZeros(const std::string& str){
        int idx = 0;
        while(str[idx] == '0'){
            idx++;
        }
        return (idx == 0) ? str : str.substr(idx);
    }
public:
    std::string multiply(std::string num1, std::string num2) {

        if(num1 == "0" || num2 == "0")
            return "0";

        std::vector<int> product(num1.size() + num2.size(), 0);

        multiDigi(num1, num2, product);

        std::string result =  To_String(product);

        return removeZeros(result);
    }
};


int main() {
    Solution solution;
    std::cout << solution.multiply("2", "3") << std::endl;
    return 0;
}
