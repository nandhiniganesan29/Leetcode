class Solution {
    public int minDistance(String word1, String word2) {
        int m = word1.length();
        int n = word2.length();
        
        // dp[i][j] will be the minimum distance from word1[0..i-1] to word2[0..j-1]
        int[][] dp = new int[m + 1][n + 1];
        
        // Base case: transforming word1 into an empty string (deletions)
        for (int i = 0; i <= m; i++) {
            dp[i][0] = i;
        }
        
        // Base case: transforming an empty string into word2 (insertions)
        for (int j = 0; j <= n; j++) {
            dp[0][j] = j;
        }
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1.charAt(i - 1) == word2.charAt(j - 1)) {
                    // Characters match, no new operation needed
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    // Characters don't match, take the minimum of 3 operations:
                    // 1. Replace: dp[i-1][j-1] + 1
                    // 2. Delete:  dp[i-1][j] + 1
                    // 3. Insert:  dp[i][j-1] + 1
                    dp[i][j] = 1 + Math.min(dp[i - 1][j - 1], 
                                   Math.min(dp[i - 1][j], dp[i][j - 1]));
                }
            }
        }
        
        return dp[m][n];
    }
}
