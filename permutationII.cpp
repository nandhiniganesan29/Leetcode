#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Comparison function for qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void backtrack(int* nums, int numsSize, int** result, int* returnSize, int* current, bool* used, int depth) {
    if (depth == numsSize) {
        // Found a valid permutation, copy it to result
        result[*returnSize] = (int*)malloc(numsSize * sizeof(int));
        memcpy(result[*returnSize], current, numsSize * sizeof(int));
        (*returnSize)++;
        return;
    }

    for (int i = 0; i < numsSize; i++) {
        // Skip if already used
        if (used[i]) continue;
        
        // Skip duplicates: if the current element is the same as the previous 
        // and the previous wasn't used in this path, it's a duplicate branch
        if (i > 0 && nums[i] == nums[i-1] && !used[i-1]) continue;

        used[i] = true;
        current[depth] = nums[i];
        backtrack(nums, numsSize, result, returnSize, current, used, depth + 1);
        
        // Backtrack
        used[i] = false;
    }
}

int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    // Sort to handle duplicates easily
    qsort(nums, numsSize, sizeof(int), compare);

    // Max possible permutations for length 8 is 8! = 40320
    int maxPermutations = 40320; 
    int** result = (int**)malloc(maxPermutations * sizeof(int*));
    bool* used = (bool*)calloc(numsSize, sizeof(bool));
    int* current = (int*)malloc(numsSize * sizeof(int));
    
    *returnSize = 0;
    backtrack(nums, numsSize, result, returnSize, current, used, 0);

    // Set column sizes for each permutation
    *returnColumnSizes = (int*)malloc((*returnSize) * sizeof(int));
    for (int i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = numsSize;
    }

    free(used);
    free(current);
    return result;
}
