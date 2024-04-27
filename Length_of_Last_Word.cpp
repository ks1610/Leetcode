#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int pre = 0, cur = 0; // previous length & current length

        for(auto i : s) {
            if(i != ' ') // increase current length if i != ' ' symbol
                cur++;
            else {
                if(cur != 0) { // if current length != 0,
                    pre = cur; // previous length = current length and current length = 0
                    cur = 0;
                }
            }
        }
        if(cur != 0)
            pre = cur;

        return pre; // return the previous length
    }
};

int main() {
    Solution solution;
    string input = "Hello World";
    int result = solution.lengthOfLastWord(input);
    cout << "Length of last word: " << result << endl;
    return 0;
}
