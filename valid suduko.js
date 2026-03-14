import java.util.HashSet;
import java.util.Set;

class Solution {
    public boolean isValidSudoku(char[][] board) {
        // Use a Set to store strings representing seen numbers
        // Format: "digit in row i", "digit in col j", "digit in block b"
        Set<String> seen = new HashSet<>();

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char number = board[i][j];
                
                if (number != '.') {
                    // Check if this digit has already appeared in this row, col, or block
                    if (!seen.add(number + " in row " + i) ||
                        !seen.add(number + " in col " + j) ||
                        !seen.add(number + " in block " + (i / 3) * 3 + (j / 3))) {
                        return false;
                    }
                }
            }
        }

        return true;
    }
