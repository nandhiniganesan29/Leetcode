#include <stdlib.h>

// Helper for sorting (if using O(n log n) approach)
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int longestConsecutive(int* nums, int numsSize) {
    if (numsSize == 0) return 0;

    // Sort to handle duplicates and sequence counting
    qsort(nums, numsSize, sizeof(int), compare);

    int longestStreak = 1;
    int currentStreak = 1;

    for (int i = 1; i < numsSize; i++) {
        // Skip duplicates
        if (nums[i] != nums[i - 1]) {
            // Check if consecutive
            if (nums[i] == nums[i - 1] + 1) {
                currentStreak++;
            } else {
                // Sequence broken, update longest and reset current
                if (currentStreak > longestStreak) longestStreak = currentStreak;
                currentStreak = 1;
            }
        }
    }

    return (currentStreak > longestStreak) ? currentStreak : longestStreak;
}
