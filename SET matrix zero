class Solution {
    public void setZeroes(int[][] matrix) {
        int rows = matrix.length;
        int cols = matrix[0].length;
        boolean firstRowZero = false;
        boolean firstColZero = false;

        // 1. Check if the first row or first column needs to be zeroed eventually
        for (int i = 0; i < rows; i++) {
            if (matrix[i][0] == 0) firstColZero = true;
        }
        for (int j = 0; j < cols; j++) {
            if (matrix[0][j] == 0) firstRowZero = true;
        }

        // 2. Use the first row and first col as markers
        // Start from (1,1) and mark the corresponding headers if a 0 is found
        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < cols; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // 3. Zero out cells based on the markers in the first row/col
        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < cols; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // 4. Finally, zero out the first row and first column if needed
        if (firstColZero) {
            for (int i = 0; i < rows; i++) matrix[i][0] = 0;
        }
        if (firstRowZero) {
            for (int j = 0; j < cols; j++) matrix[0][j] = 0;
        }
    }
}
