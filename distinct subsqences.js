class Solution {
    public int numDistinct(String s, String t) {
        int n = s.length();
        int m = t.length();
        
        // dp[j] will store the number of distinct subsequences of 
        // s (prefix currently being processed) that equal t[0...j-1]
        int[] dp = new int[m + 1];
        
        // Base case: There is exactly one way to form an empty t
        dp[0] = 1;
        
        for (int i = 1; i <= n; i++) {
            // Traverse t backward to avoid using updated values from the same row
            for (int j = m; j >= 1; j--) {
                // If characters match, we can either:
                // 1. Use s.charAt(i-1) to match t.charAt(j-1) -> dp[j-1]
                // 2. Skip s.charAt(i-1) and use previous matches -> dp[j]
                if (s.charAt(i - 1) == t.charAt(j - 1)) {
                    dp[j] = dp[j] + dp[j - 1];
                }
                // If characters don't match, we just carry forward dp[j]
            }
        }
        
        return dp[m];
    }
}
