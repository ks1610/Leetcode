#include <unordered_map>
#include <string>
#include <algorithm>


class Solution {
public:
    string convertToTitle(int columnNumber) {
        std::unordered_map<int,char>mp={
            {1,'A'},{2,'B'},{3,'C'},{4,'D'},{5,'E'},{6,'F'},{7,'G'},{8,'H'},
            {9,'I'},{10,'J'},{11,'K'},{12,'L'},{13,'M'},{14,'N'},{15,'O'},{16,'P'},
            {17,'Q'},{18,'R'},{19,'S'},{20,'T'},{21,'U'},{22,'V'},{23,'W'},{24,'X'},
            {25,'Y'},{26,'Z'},{0,'Z'}
        };

        std::string ans = "";

        int num = columnNumber;

        while(num > 0){
            int sur = num % 26;

            if(sur == 0){
                num--;
            } 

            ans+=mp[sur];
            num/=26;
        }

        reverse(ans.begin(),ans.end());        

        return ans;
    }
};


int main() {
    Solution sol;

    // Test cases
    std::cout << "Input: 1 -> Output: " << sol.convertToTitle(1) << " (Expected: A)" << std::endl;
    std::cout << "Input: 26 -> Output: " << sol.convertToTitle(26) << " (Expected: Z)" << std::endl;
    std::cout << "Input: 27 -> Output: " << sol.convertToTitle(27) << " (Expected: AA)" << std::endl;
    std::cout << "Input: 28 -> Output: " << sol.convertToTitle(28) << " (Expected: AB)" << std::endl;
    std::cout << "Input: 52 -> Output: " << sol.convertToTitle(52) << " (Expected: AZ)" << std::endl;
    std::cout << "Input: 701 -> Output: " << sol.convertToTitle(701) << " (Expected: ZY)" << std::endl;
    std::cout << "Input: 702 -> Output: " << sol.convertToTitle(702) << " (Expected: ZZ)" << std::endl;
    std::cout << "Input: 703 -> Output: " << sol.convertToTitle(703) << " (Expected: AAA)" << std::endl;

    return 0;
}
