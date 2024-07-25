class Solution(object):
    # Depth-first search (DFS) helper method
    def dfs(self, board, i, j):
        # Get the number of rows (m) and columns (n) of the board
        m = len(board)
        n = len(board[0])
        # Define possible directions to move: right, down, left, up
        direction = [(1, 0), (0, 1), (-1, 0), (0, -1)]
        # Mark the current cell as visited with 'Y'
        board[i][j] = 'Y'
        # Iterate over all possible directions
        for x, y in direction:
            # Calculate the new cell coordinates
            ix = i + x
            jy = j + y
            # Check if the new cell is within bounds and is an 'O'
            if 0 <= ix < m and 0 <= jy < n and board[ix][jy] == 'O':
                # Recursively call dfs for the new cell
                self.dfs(board, ix, jy)

    # Main method to solve the problem
    def solve(self, board):
        """
        :type board: List[List[str]]
        :rtype: None
        """
        # Get the number of rows (m) and columns (n) of the board
        m = len(board)
        n = len(board[0])
        # Return if the board is empty
        if m == 0 or n == 0:
            return

        # Perform DFS for 'O's on the border
        for i in range(m):
            for j in range(n):
                # Check if the cell is on the border and contains 'O'
                if i == 0 or i == m - 1 or j == 0 or j == n - 1:
                    if board[i][j] == 'O':
                        # Call dfs to mark the connected 'O's
                        self.dfs(board, i, j)

        # Change all remaining 'O's to 'X'
        for i in range(m):
            for j in range(n):
                if board[i][j] == 'O':
                    board[i][j] = 'X'

        # Change all 'Y's back to 'O'
        for i in range(m):
            for j in range(n):
                if board[i][j] == 'Y':
                    board[i][j] = 'O'

# Example usage:
board = [
    ['X', 'X', 'X', 'X'],
    ['X', 'O', 'O', 'X'],
    ['X', 'X', 'O', 'X'],
    ['X', 'O', 'X', 'X']
]

# Create an instance of Solution
solution = Solution()
# Solve the board
solution.solve(board)

# Print the board after solving
for row in board:
    print(' '.join(row))
