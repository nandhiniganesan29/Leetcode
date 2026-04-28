#include <stdlib.h>
#include <string.h>

// Comparison function for qsort
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

void backtrack(int* nums, int numsSize, int start, int* path, int pathSize, 
               int*** res, int* resSize, int** colSizes) {
    
    // Add current path to results
    (*res)[*resSize] = (int*)malloc(pathSize * sizeof(int));
    memcpy((*res)[*resSize], path, pathSize * sizeof(int));
    (*colSizes)[*resSize] = pathSize;
    (*resSize)++;

    for (int i = start; i < numsSize; i++) {
        // Skip duplicates: if current element is same as previous and not at start of recursion
        if (i > start && nums[i] == nums[i - 1]) continue;

        path[pathSize] = nums[i];
        backtrack(nums, numsSize, i + 1, path, pathSize + 1, res, resSize, colSizes);
    }
}

int** subsetsWithDup(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    // Sort to handle duplicates
    qsort(nums, numsSize, sizeof(int), compare);

    int maxSubsets = 1 << numsSize; // Upper bound for allocation
    int** res = (int**)malloc(maxSubsets * sizeof(int*));
    *returnColumnSizes = (int*)malloc(maxSubsets * sizeof(int));
    *returnSize = 0;

    int* path = (int*)malloc(numsSize * sizeof(int));
    
    backtrack(nums, numsSize, 0, path, 0, &res, returnSize, returnColumnSizes);

    free(path);
    return res;
}
