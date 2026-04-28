#include <stdlib.h>
#include <math.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* grayCode(int n, int* returnSize) {
    // Total numbers in the sequence is 2^n
    int size = 1 << n; 
    *returnSize = size;
    
    int* result = (int*)malloc(size * sizeof(int));
    if (result == NULL) return NULL;

    for (int i = 0; i < size; i++) {
        /* 
           Gray code formula: G(i) = i ^ (i / 2)
           This ensures only one bit changes between consecutive numbers.
        */
        result[i] = i ^ (i >> 1);
    }

    return result;
}
