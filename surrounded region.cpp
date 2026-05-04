void dfs(char** board, int r, int c, int rows, int cols) {
    // Boundary check and check if cell is 'O'
    if (r < 0 || r >= rows || c < 0 || c >= cols || board[r][c] != 'O') {
        return;
    }

    // Mark as visited/safe
    board[r][c] = '#';

    // Explore neighbors
    dfs(board, r + 1, c, rows, cols);
    dfs(board, r - 1, c, rows, cols);
    dfs(board, r, c + 1, rows, cols);
    dfs(board, r, c - 1, rows, cols);
}

void solve(char** board, int boardSize, int* boardColSize) {
    if (boardSize == 0) return;
    int rows = boardSize;
    int cols = boardColSize[0];

    // 1. Traverse borders to find 'O's and mark their connected components
    for (int i = 0; i < rows; i++) {
        dfs(board, i, 0, rows, cols);        // Left border
        dfs(board, i, cols - 1, rows, cols); // Right border
    }
    for (int j = 0; j < cols; j++) {
        dfs(board, 0, j, rows, cols);        // Top border
        dfs(board, rows - 1, j, rows, cols); // Bottom border
    }

    // 2. Process the board
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (board[i][j] == 'O') {
                board[i][j] = 'X'; // Captured
            } else if (board[i][j] == '#') {
                board[i][j] = 'O'; // Safe
            }
        }
    }
}
