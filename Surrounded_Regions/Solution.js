/**
 * @param {character[][]} board
 * @return {void} Do not return anything, modify board in-place instead.
 */

// Helper function to perform depth-first search (DFS)
function dfs(board, i, j) {
    let m = board.length;       // Get the number of rows
    let n = board[0].length;    // Get the number of columns
    let movement = [[0,1],[0,-1],[1,0],[-1,0]];  // Define possible movements: right, left, down, up
    
    board[i][j] = 'Y';  // Mark the current cell as visited by changing 'O' to 'Y'
    
    // Iterate over each possible movement direction
    for (let d of movement) {
        let ix = i + d[0];  // Calculate new row index
        let jy = j + d[1];  // Calculate new column index
        
        // Check if the new cell is within bounds and is 'O'
        if (ix >= 0 && ix < m && jy >= 0 && jy < n && board[ix][jy] === 'O') {
            dfs(board, ix, jy);  // Recursively call dfs on the new cell
        }
    }
}

// Main function to solve the problem
var solve = function(board) {
    let m = board.length;  // Get the number of rows
    let n = board[0].length;  // Get the number of columns
    
    // If the board is empty, return immediately
    if (m == 0) return;

    // Perform DFS for 'O's on the border
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (i === 0 || j === 0 || i === m - 1 || j === n - 1) {  // Check if the cell is on the border
                if (board[i][j] === 'O')  // If the cell is 'O', perform DFS
                    dfs(board, i, j);
            }
        }
    }

    // Change all remaining 'O's to 'X'
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (board[i][j] === 'O')
                board[i][j] = 'X';
        }
    }

    // Change all 'Y's back to 'O'
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (board[i][j] === 'Y')
                board[i][j] = 'O';
        }
    }
};

// Testing the output
let board = [
    ['X', 'X', 'X', 'X'],
    ['X', 'O', 'O', 'X'],
    ['X', 'X', 'O', 'X'],
    ['X', 'O', 'X', 'X']
];

console.log("Board before solving:");
board.forEach(row => console.log(row.join(' ')));

solve(board);

console.log("Board after solving:");
board.forEach(row => console.log(row.join(' ')));
