#include <string.h>

int numDecodings(char* s) {
    if (s == NULL || s[0] == '0') return 0;
    
    int n = strlen(s);
    // dp[i] stores the number of ways to decode the prefix of length i
    int dp[n + 1];
    memset(dp, 0, sizeof(dp));
    
    dp[0] = 1; // Base case: an empty string has one way to be decoded
    dp[1] = 1; // We already checked s[0] != '0', so prefix of length 1 has one way
    
    for (int i = 2; i <= n; i++) {
        // Single digit check (s[i-1])
        int oneDigit = s[i - 1] - '0';
        if (oneDigit >= 1 && oneDigit <= 9) {
            dp[i] += dp[i - 1];
        }
        
        // Two digit check (s[i-2] and s[i-1])
        int twoDigits = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
        if (twoDigits >= 10 && twoDigits <= 26) {
            dp[i] += dp[i - 2];
        }
    }
    
    return dp[n];
}
