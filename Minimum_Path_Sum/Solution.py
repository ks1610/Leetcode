class Solution(object):
    def minPathSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        m = len(grid)
        n = len(grid[0])
        
        for i in range(1, m):
            grid[i][0] += grid[i-1][0]
        
        for j in range(1, n):
            grid[0][j] += grid[0][j-1]
        
        for i in range(1, m):
            for j in range(1, n):
                grid[i][j] += min(grid[i-1][j], grid[i][j-1])
        
        return grid[m-1][n-1]


if __name__ == "__main__":
    m = int(input("Enter number of rows: "))
    n = int(input("Enter number of columns: "))

    print("Enter grid values row by row:")
    grid = []
    for _ in range(m):
        row = list(map(int, input().split()))
        grid.append(row)

    sol = Solution()
    result = sol.minPathSum(grid)

    print("Minimum Path Sum =", result)
