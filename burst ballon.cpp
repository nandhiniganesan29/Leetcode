#include <string.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int maxCoins(int* nums, int numsSize) {
    int n = numsSize;
    
    // Step 1: Create a new array padded with 1s at both boundaries
    // Size is n + 2. Max size needed is 302.
    int ball[305]; 
    ball[0] = 1;
    ball[n + 1] = 1;
    for (int i = 0; i < n; i++) {
        ball[i + 1] = nums[i];
    }
    
    // dp[i][j] stores the max coins obtained by bursting all balloons between i and j (exclusive)
    // Using a static/stack array is much faster than malloc for LeetCode constraints
    int dp[305][305];
    memset(dp, 0, sizeof(dp));
    
    // Step 2: Iterate through all possible sub-array lengths
    for (int len = 1; len <= n; len++) {
        // i is the left boundary (exclusive)
        for (int i = 0; i <= n - len + 1; i++) {
            // j is the right boundary (exclusive)
            int j = i + len + 1;
            int baseCoins = ball[i] * ball[j]; // Optimization: compute once per interval
            
            // k is the index of the LAST balloon to pop in the interval (i, j)
            for (int k = i + 1; k < j; k++) {
                int coins = dp[i][k] + dp[k][j] + (baseCoins * ball[k]);
                dp[i][j] = MAX(dp[i][j], coins);
            }
        }
    }
    
    // The answer is the maximum coins for the entire padded range
    return dp[0][n + 1];
}
