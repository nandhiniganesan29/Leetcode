class Solution {
    public int minCut(String s) {
        int n = s.length();
        if (n <= 1) return 0;

        // cuts[i] is the min cuts for s[0...i]
        int[] cuts = new int[n];
        // isPal[i][j] is true if s[i...j] is a palindrome
        boolean[][] isPal = new boolean[n][n];

        for (int i = 0; i < n; i++) {
            // Maximum possible cuts for s[0...i] is i (cutting every char)
            int minCuts = i;
            
            for (int j = 0; j <= i; j++) {
                // Check if s[j...i] is a palindrome
                // 1. Chars at j and i must match
                // 2. Inner substring s[j+1...i-1] must be a palindrome or length < 2
                if (s.charAt(i) == s.charAt(j) && (i - j <= 2 || isPal[j + 1][i - 1])) {
                    isPal[j][i] = true;
                    
                    // If s[0...i] is a palindrome, 0 cuts needed
                    if (j == 0) {
                        minCuts = 0;
                    } else {
                        // Otherwise, min cuts is 1 + min cuts of the prefix
                        minCuts = Math.min(minCuts, cuts[j - 1] + 1);
                    }
                }
            }
            cuts[i] = minCuts;
        }

        return cuts[n - 1];
    }
}
