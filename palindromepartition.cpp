#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Helper to check if a substring is a palindrome
bool isPalindrome(char* s, int start, int end) {
    while (start < end) {
        if (s[start++] != s[end--]) return false;
    }
    return true;
}

// Backtracking function
void backtrack(char* s, int start, int n, char** currentPath, int pathIdx, 
               char**** results, int* resSize, int** colSizes) {
    if (start == n) {
        // Found a valid partitioning!
        (*results)[*resSize] = malloc(pathIdx * sizeof(char*));
        for (int i = 0; i < pathIdx; i++) {
            (*results)[*resSize][i] = strdup(currentPath[i]);
        }
        (*colSizes)[*resSize] = pathIdx;
        (*resSize)++;
        return;
    }

    for (int end = start; end < n; end++) {
        if (isPalindrome(s, start, end)) {
            // Calculate length of the substring
            int len = end - start + 1;
            char* sub = malloc((len + 1) * sizeof(char));
            strncpy(sub, s + start, len);
            sub[len] = '\0';

            currentPath[pathIdx] = sub;
            backtrack(s, end + 1, n, currentPath, pathIdx + 1, results, resSize, colSizes);
            
            // Backtrack: free the allocated substring
            free(sub);
        }
    }
}

char*** partition(char* s, int* returnSize, int** returnColumnSizes) {
    int n = strlen(s);
    *returnSize = 0;
    
    // Pre-allocate memory (using a large enough estimate or dynamic reallocation)
    char*** results = malloc(2000 * sizeof(char**));
    *returnColumnSizes = malloc(2000 * sizeof(int));
    char** currentPath = malloc(n * sizeof(char*));

    backtrack(s, 0, n, currentPath, 0, &results, returnSize, returnColumnSizes);

    free(currentPath);
    return results;
}
