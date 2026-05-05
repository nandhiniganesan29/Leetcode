#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int maximumGap(int* nums, int numsSize) {
    if (numsSize < 2) return 0;

    int minVal = INT_MAX, maxVal = INT_MIN;
    for (int i = 0; i < numsSize; i++) {
        minVal = MIN(minVal, nums[i]);
        maxVal = MAX(maxVal, nums[i]);
    }

    if (minVal == maxVal) return 0;

    // Calculate bucket size and count
    int bucketSize = MAX(1, (maxVal - minVal) / (numsSize - 1));
    int bucketCount = (maxVal - minVal) / bucketSize + 1;

    // Use two arrays to store the min and max values of each bucket
    int* minBuckets = (int*)malloc(bucketCount * sizeof(int));
    int* maxBuckets = (int*)malloc(bucketCount * sizeof(int));
    for (int i = 0; i < bucketCount; i++) {
        minBuckets[i] = INT_MAX;
        maxBuckets[i] = INT_MIN;
    }

    // Distribute elements into buckets
    for (int i = 0; i < numsSize; i++) {
        int idx = (nums[i] - minVal) / bucketSize;
        minBuckets[idx] = MIN(minBuckets[idx], nums[i]);
        maxBuckets[idx] = MAX(maxBuckets[idx], nums[i]);
    }

    // Find the maximum gap between buckets
    int maxGap = 0;
    int prevMax = minVal;
    for (int i = 0; i < bucketCount; i++) {
        // Skip empty buckets
        if (minBuckets[i] == INT_MAX) continue;
        
        maxGap = MAX(maxGap, minBuckets[i] - prevMax);
        prevMax = maxBuckets[i];
    }

    free(minBuckets);
    free(maxBuckets);
    return maxGap;
}
