#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isValid(char** board, int row, int col, int n) {
    for (int i = 0; i < col; i++)
        if (board[row][i] == 'Q')
            return false;

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 'Q')
            return false;

    for (int i = row, j = col; i < n && j >= 0; i++, j--)
        if (board[i][j] == 'Q')
            return false;

    return true;
}

void copySolution(char** board, int n, char*** result, int* returnSize, int** returnColumnSizes) {
    result[*returnSize] = (char**)malloc(n * sizeof(char*));
    (*returnColumnSizes)[*returnSize] = n;

    for (int i = 0; i < n; i++) {
        result[*returnSize][i] = (char*)malloc((n + 1) * sizeof(char));
        strcpy(result[*returnSize][i], board[i]);
    }

    (*returnSize)++;
}

void solve(int col, int n, char** board, char*** result, int* returnSize, int** returnColumnSizes) {
    if (col == n) {
        copySolution(board, n, result, returnSize, returnColumnSizes);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (isValid(board, i, col, n)) {
            board[i][col] = 'Q';
            solve(col + 1, n, board, result, returnSize, returnColumnSizes);
            board[i][col] = '.';
        }
    }
}

char*** solveNQueens(int n, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;

    // Allocate max possible solutions (n!), you can optimize this later
    int maxSolutions = 1000;
    char*** result = (char***)malloc(maxSolutions * sizeof(char**));
    *returnColumnSizes = (int*)malloc(maxSolutions * sizeof(int));

    // Create board
    char** board = (char**)malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++) {
        board[i] = (char*)malloc(n + 1);
        memset(board[i], '.', n);
        board[i][n] = '\0';
    }

    solve(0, n, board, result, returnSize, returnColumnSizes);

    // Free board
    for (int i = 0; i < n; i++)
        free(board[i]);
    free(board);

    return result;
}

// Test
int main() {
    int n = 4;
    int returnSize;
    int* returnColumnSizes;
    char*** solutions = solveNQueens(n, &returnSize, &returnColumnSizes);

    for (int i = 0; i < returnSize; i++) {
        printf("Solution %d:\n", i + 1);
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%s\n", solutions[i][j]);
            free(solutions[i][j]);
        }
        free(solutions[i]);
        printf("\n");
    }

    free(solutions);
    free(returnColumnSizes);

    return 0;
}
