import java.util.*;

class Solution {
    public List<List<String>> solveNQueens(int n) {
        List<List<String>> result = new ArrayList<>();
        char[][] board = new char[n][n];
        
        // Initialize the board with empty spaces
        for (int i = 0; i < n; i++) {
            Arrays.fill(board[i], '.');
        }
        
        backtrack(result, board, 0, n);
        return result;
    }

    private void backtrack(List<List<String>> result, char[][] board, int row, int n) {
        // Base case: If we've placed queens in all rows, add the board to results
        if (row == n) {
            result.add(construct(board));
            return;
        }

        for (int col = 0; col < n; col++) {
            if (isSafe(board, row, col, n)) {
                board[row][col] = 'Q';       // Place queen
                backtrack(result, board, row + 1, n);
                board[row][col] = '.';       // Backtrack (remove queen)
            }
        }
    }

    private boolean isSafe(char[][] board, int row, int col, int n) {
        // Check column (only check rows above)
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') return false;
        }

        // Check 45-degree diagonal (upper left)
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') return false;
        }

        // Check 135-degree diagonal (upper right)
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') return false;
        }

        return true;
    }

    private List<String> construct(char[][] board) {
        List<String> res = new ArrayList<>();
        for (int i = 0; i < board.length; i++) {
            res.add(new String(board[i]));
        }
        return res;
    }
}
