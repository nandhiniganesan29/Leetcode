class Solution {
    // Four directional moves: Up, Down, Left, Right
    private static final int[][] DIRECTIONS = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    public int longestIncreasingPath(int[][] matrix) {
        if (matrix == null || matrix.length == 0 || matrix[0].length == 0) {
            return 0;
        }

        int m = matrix.length;
        int n = matrix[0].length;
        
        // memo[r][c] stores the longest increasing path starting from cell (r, c)
        int[][] memo = new int[m][n];
        int maxPath = 0;

        // Calculate the longest path starting from every cell in the matrix
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                int pathLen = dfs(matrix, r, c, memo);
                maxPath = Math.max(maxPath, pathLen);
            }
        }

        return maxPath;
    }

    private int dfs(int[][] matrix, int r, int c, int[][] memo) {
        // If the value has already been computed, return it immediately (Memoization)
        if (memo[r][c] != 0) {
            return memo[r][c];
        }

        // Every individual cell forms a path of at least length 1
        int max = 1;

        // Explore all 4 adjacent directions
        for (int[] dir : DIRECTIONS) {
            int nextR = r + dir[0];
            int nextC = c + dir[1];

            // Verify boundaries and strict increasing order condition
            if (nextR >= 0 && nextR < matrix.length && nextC >= 0 && nextC < matrix[0].length 
                && matrix[nextR][nextC] > matrix[r][c]) {
                
                int path = 1 + dfs(matrix, nextR, nextC, memo);
                max = Math.max(max, path);
            }
        }

        // Save the calculated value to the cache before returning
        memo[r][c] = max;
        return max;
    }
}
