#include <string.h>
#include <stdlib.h>

char* addBinary(char* a, char* b) {
    int i = strlen(a) - 1;
    int j = strlen(b) - 1;
    int carry = 0;
    
    // Max length of result is max(len_a, len_b) + 1 (for carry) + 1 (for null terminator)
    int maxLen = (i > j ? i : j) + 3;
    char* res = (char*)malloc(maxLen * sizeof(char));
    res[maxLen - 1] = '\0';
    int k = maxLen - 2;

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';
        
        res[k--] = (sum % 2) + '0';
        carry = sum / 2;
    }

    // Return pointer shifted to the start of the actual digits
    return &res[k + 1];
}
