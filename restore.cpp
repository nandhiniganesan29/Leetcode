#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isValid(char* s, int start, int len) {
    if (len > 3 || len == 0) return false;
    // Leading zero check: "0" is okay, "01", "001" are not.
    if (len > 1 && s[start] == '0') return false;
    
    int val = 0;
    for (int i = start; i < start + len; i++) {
        val = val * 10 + (s[i] - '0');
    }
    return val <= 255;
}

void backtrack(char* s, int start, int segment, char* current, char*** res, int* resSize) {
    int n = strlen(s);
    
    // If we have 4 segments and reached the end of the string
    if (segment == 4) {
        if (start == n) {
            char* temp = strdup(current);
            temp[strlen(temp) - 1] = '\0'; // Remove trailing dot
            (*res)[(*resSize)++] = temp;
        }
        return;
    }

    for (int len = 1; len <= 3 && start + len <= n; len++) {
        if (isValid(s, start, len)) {
            int curLen = strlen(current);
            // Append segment and a dot
            strncat(current, s + start, len);
            strcat(current, ".");
            
            backtrack(s, start + len, segment + 1, current, res, resSize);
            
            // Backtrack: reset the string to its previous length
            current[curLen] = '\0';
        }
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** restoreIpAddresses(char* s, int* returnSize) {
    int n = strlen(s);
    *returnSize = 0;
    if (n < 4 || n > 12) return NULL;

    // Maximum possible valid IPs is not very large (math.comb(11, 3))
    char** res = (char**)malloc(100 * sizeof(char*));
    char* current = (char*)calloc(20, sizeof(char)); // IP max length is 15 + 4 dots + null

    backtrack(s, 0, 0, current, &res, returnSize);

    free(current);
    return res;
}
