#include <bits/stdc++.h>

class Solution {
public:
    void setZeroes(std::vector<std::vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();

        std::vector<int> row(n, 0);

        std::vector<int> col(m, 0);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == 0)
                {
                    // mark ith index of row wih 1:
                    row[i] = 1;

                    // mark jth index of col wih 1:
                    col[j] = 1;
                }
            }
        }
        
        // 1st pass done, now we have to set all the 0s in the matrix
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (row[i] || col[j])
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

int main(){
    Solution s;
    std::vector<std::vector<int>> matrix = {{1,1,1},{1,0,1},{1,1,1}};
    s.setZeroes(matrix);
    for (auto& row : matrix)
    {
        for (auto& col : row)
        {
            std::cout << col << " ";
        }
        std::cout << std::endl;
    }
}
