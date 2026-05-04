#include <ctype.h>
#include <stdbool.h>
#include <string.h>

bool isPalindrome(char* s) {
    int left = 0;
    int right = strlen(s) - 1;

    while (left < right) {
        // Skip non-alphanumeric characters from the left
        if (!isalnum(s[left])) {
            left++;
        } 
        // Skip non-alphanumeric characters from the right
        else if (!isalnum(s[right])) {
            right--;
        } 
        // Compare characters
        else {
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }
            left++;
            right--;
        }
    }

    return true;
}
