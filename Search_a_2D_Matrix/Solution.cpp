#include <bits/stdc++.h>

class Solution {
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {

        if(matrix.empty() || matrix[0].empty()) return false;

        int m = matrix.size(), n = matrix[0].size();
        int left = 0, right = m * n - 1;
        
        while(left <= right){
            int mid = (left+right) / 2;
            int mid_val = matrix[mid / n][mid % n];
            
            if(mid_val == target)
                return true;
            else if(mid_val < target)
                left = mid + 1;
            else
                right = mid - 1;
        }

        return false;
    }
};
int main(){
    Solution s;
    std::vector<std::vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    std::cout << s.searchMatrix(matrix, 3) << std::endl;
    return 0;
}
