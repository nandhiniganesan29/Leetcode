int numTrees(int n) {
    // dp[i] stores the number of unique BSTs that can be formed with i nodes
    int dp[n + 1];
    
    // Base cases
    dp[0] = 1; // Empty tree
    dp[1] = 1; // Single node tree
    
    // Fill the dp table using the recurrence relation:
    // dp[i] = sum(dp[j-1] * dp[i-j]) for j from 1 to i
    for (int i = 2; i <= n; i++) {
        dp[i] = 0;
        for (int j = 1; j <= i; j++) {
            // j is the root node
            // left subtree has (j-1) nodes
            // right subtree has (i-j) nodes
            dp[i] += dp[j - 1] * dp[i - j];
        }
    }
    
    return dp[n];
}
