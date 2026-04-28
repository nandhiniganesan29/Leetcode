class Solution {
    public int minPathSum(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;

        // Use the grid itself to save space (In-place DP)
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue; // Start cell

                if (i == 0) {
                    // Top row: can only come from the left
                    grid[i][j] += grid[i][j - 1];
                } else if (j == 0) {
                    // Left column: can only come from above
                    grid[i][j] += grid[i - 1][j];
                } else {
                    // Inner cells: take the cheaper path
                    grid[i][j] += Math.min(grid[i - 1][j], grid[i][j - 1]);
                }
            }
        }

        return grid[m - 1][n - 1];
    }
}
