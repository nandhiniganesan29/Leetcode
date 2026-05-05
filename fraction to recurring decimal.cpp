#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* fractionToDecimal(int numerator, int denominator) {
    if (numerator == 0) return strdup("0");

    // Use long long to prevent overflow (e.g., abs(INT_MIN))
    long long n = numerator;
    long long d = denominator;
    
    char* res = (char*)malloc(10000); // Problem guarantees length < 10^4
    int pos = 0;

    // 1. Handle Sign
    if ((n < 0) ^ (d < 0)) res[pos++] = '-';
    n = llabs(n);
    d = llabs(d);

    // 2. Integer Part
    pos += sprintf(&res[pos], "%lld", n / d);
    long long remainder = n % d;
    if (remainder == 0) {
        res[pos] = '\0';
        return res;
    }

    // 3. Decimal Part
    res[pos++] = '.';
    
    // Track remainders and their positions to find cycles
    // For a production-grade C solution, use a real Hash Map. 
    // Here we use a simple tracking array for clarity.
    long long seen_rem[10000];
    int seen_pos[10000];
    int count = 0;

    while (remainder != 0) {
        // Check if remainder was seen before
        for (int i = 0; i < count; i++) {
            if (seen_rem[i] == remainder) {
                // Cycle detected: insert '(' at seen_pos[i]
                int start = seen_pos[i];
                memmove(&res[start + 1], &res[start], pos - start);
                res[start] = '(';
                res[++pos] = ')';
                res[++pos] = '\0';
                return res;
            }
        }

        // Store current remainder and its string position
        seen_rem[count] = remainder;
        seen_pos[count++] = pos;

        remainder *= 10;
        res[pos++] = (remainder / d) + '0';
        remainder %= d;
    }

    res[pos] = '\0';
    return res;
}
