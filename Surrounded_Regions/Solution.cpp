class Solution {
public:
    void dfs(std::vector<std::vector<char>>& board, int i, int j) {
        // Get the dimensions of the board
        int m = board.size();
        int n = board[0].size();

         // Define the direction vectors for moving in 4 possible directions
        std::vector<std::vector<int>> dir {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        board[i][j] = 'Y';  // Mark the cell as 'Y' to indicate it has been visited
        for (const auto& d : dir) { // Explore all 4 directions
            int ix = i + d[0]; 
            int jy = j + d[1];
            // Ensure the next cell is within valid bounds and contains 'O'
            if (ix >= 0 && ix < m && jy >= 0 && jy < n && board[ix][jy] == 'O') {
                dfs(board, ix, jy); // Recursively perform DFS
            }
        }
    }

    void solve(std::vector<std::vector<char>>& board) {
        int m = board.size();
        if (m == 0) 
            return;   // If the board is empty, return immediately
        int n = board[0].size();

        // Mark all 'O's connected to the border       
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    if (board[i][j] == 'O') {
                        dfs(board, i, j);  // Start DFS from border 'O's
                    }
                }
            }
        }
        
        // Flip all surrounded 'O's to 'X'
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }

        // Restore all border-connected 'O's back to 'O'        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'Y') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};

int main(){
    Solution s;
    std::vector<std::vector<char>> board = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}
    };

    //before solve
    for (const auto& row : board) {
        for (char c : row) std::cout << c << " ";
        std::cout << std::endl;
    }
    
    //after solve
    s.solve(board);
    for (const auto& row : board) {
        for (char c : row) std::cout << c << " ";
        std::cout << std::endl;
    }

}
