#include <string.h>

void reverse(char* s, int i, int j) {
    while (i < j) {
        char temp = s[i];
        s[i++] = s[j];
        s[j--] = temp;
    }
}

char* reverseWords(char* s) {
    int n = strlen(s);
    
    // 1. Reverse the entire string
    reverse(s, 0, n - 1);
    
    // 2. Reverse each word and handle spacing
    int i = 0, j = 0; // i is write pointer, j is read pointer
    while (j < n) {
        // Skip leading spaces
        while (j < n && s[j] == ' ') j++;
        if (j == n) break;
        
        // Add a single space between words if not the first word
        if (i > 0) s[i++] = ' ';
        
        int start = i;
        // Copy the word
        while (j < n && s[j] != ' ') {
            s[i++] = s[j++];
        }
        // Reverse the copied word
        reverse(s, start, i - 1);
    }
    
    // 3. Null-terminate and return
    s[i] = '\0';
    return s;
}
