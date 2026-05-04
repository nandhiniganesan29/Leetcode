#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool wordBreak(char* s, char** wordDict, int wordDictSize) {
    int n = strlen(s);
    // dp[i] is true if s[0...i-1] can be segmented
    bool* dp = (bool*)calloc(n + 1, sizeof(bool));
    
    // Base case: empty string can be segmented
    dp[0] = true;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            // If the prefix s[0...j] is valid AND s[j...i] is in the dictionary
            if (dp[j]) {
                // Extract substring s[j...i-1]
                int subLen = i - j;
                bool found = false;
                
                for (int k = 0; k < wordDictSize; k++) {
                    if (strlen(wordDict[k]) == subLen && 
                        strncmp(s + j, wordDict[k], subLen) == 0) {
                        found = true;
                        break;
                    }
                }

                if (found) {
                    dp[i] = true;
                    break; // No need to check other j's for this i
                }
            }
        }
    }

    bool result = dp[n];
    free(dp);
    return result;
}
