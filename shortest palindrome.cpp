#include <string.h>
#include <stdlib.h>

char* shortestPalindrome(char* s) {
    int n = strlen(s);
    if (n <= 1) return s;

    // 1. Create the reversed string
    char* rev = (char*)malloc(n + 1);
    for (int i = 0; i < n; i++) {
        rev[i] = s[n - 1 - i];
    }
    rev[n] = '\0';

    // 2. Build the combined string: s + "#" + rev
    int combinedLen = 2 * n + 1;
    char* combined = (char*)malloc(combinedLen + 1);
    sprintf(combined, "%s#%s", s, rev);

    // 3. KMP partial match table (LPS)
    int* lps = (int*)calloc(combinedLen, sizeof(int));
    for (int i = 1; i < combinedLen; i++) {
        int j = lps[i - 1];
        while (j > 0 && combined[i] != combined[j]) {
            j = lps[j - 1];
        }
        if (combined[i] == combined[j]) {
            j++;
        }
        lps[i] = j;
    }

    int longestPalPrefixLen = lps[combinedLen - 1];
    free(lps);
    free(combined);

    // 4. Construct result: rev[0...n-longestPalPrefixLen] + s
    int suffixToPrependLen = n - longestPalPrefixLen;
    char* result = (char*)malloc(suffixToPrependLen + n + 1);
    
    strncpy(result, rev, suffixToPrependLen);
    result[suffixToPrependLen] = '\0';
    strcat(result, s);

    free(rev);
    return result;
}
