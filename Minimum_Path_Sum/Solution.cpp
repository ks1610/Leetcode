#include <bits/stdc++.h>

class Solution {
public:
    int minPathSum(std::vector<std::vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        for (int i = 1; i < m; i++) {
            grid[i][0] += grid[i - 1][0];
        }
        for (int i = 1; i < n; i++) {
            grid[0][i] += grid[0][i - 1];
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                grid[i][j] += std::min(grid[i - 1][j], grid[i][j - 1]);
            }
        }
        return grid[m - 1][n - 1];
    }
};

int main() {
    int m, n;
    std::cout << "Enter number of rows: ";
    std::cin >> m;
    std::cout << "Enter number of columns: ";
    std::cin >> n;

    std::vector<std::vector<int>> grid(m, std::vector<int>(n));

    std::cout << "Enter grid values:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> grid[i][j];
        }
    }

    Solution sol;
    int result = sol.minPathSum(grid);

    std::cout << "Minimum Path Sum = " << result << std::endl;

    return 0;
}
