#include <stdbool.h>
#include <string.h>

bool isInterleave(char* s1, char* s2, char* s3) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int len3 = strlen(s3);

    // Length check: s3 must be the exact sum of s1 and s2
    if (len1 + len2 != len3) return false;

    // dp[i][j] means s3[0...i+j-1] is an interleaving of s1[0...i-1] and s2[0...j-1]
    bool dp[len1 + 1][len2 + 1];

    for (int i = 0; i <= len1; i++) {
        for (int j = 0; j <= len2; j++) {
            if (i == 0 && j == 0) {
                dp[i][j] = true;
            } else if (i == 0) {
                // s1 is empty, check if s2 matches s3
                dp[i][j] = dp[i][j - 1] && (s2[j - 1] == s3[i + j - 1]);
            } else if (j == 0) {
                // s2 is empty, check if s1 matches s3
                dp[i][j] = dp[i - 1][j] && (s1[i - 1] == s3[i + j - 1]);
            } else {
                // Current char of s3 matches s1 OR s2, and the previous state was valid
                dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) || 
                           (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
            }
        }
    }

    return dp[len1][len2];
}
