#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    void gen(int open, int close, std::string op, int n, std::vector<std::string> &res){
        if(open == close && open+close == n*2){
            //cout << op << " ";
            res.push_back(op);
            return;
        }
        if(open < n){
            gen(open + 1, close, op+"(", n, res);
        }
        if(close < open){
            gen(open, close + 1, op+")", n, res);
        }
    }
    vector<string> generateParenthesis(int n) {
        std::vector<std::string> res;
        gen(0,0,"",n,res);
        return res;
    }
};

int main() {
    Solution sol;
    int n;

    cout << "Enter number of pairs of parentheses: ";
    cin >> n;

    vector<string> result = sol.generateParenthesis(n);

    cout << "Generated Parentheses combinations:\n";
    for (const string &s : result)
        cout << s << endl;

    return 0;
}
