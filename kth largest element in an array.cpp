#include <stdio.h>

// Helper to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function similar to Quicksort
int partition(int* nums, int left, int right) {
    int pivot = nums[right]; // Choosing the last element as pivot
    int i = left;
    for (int j = left; j < right; j++) {
        if (nums[j] <= pivot) {
            swap(&nums[i], &nums[j]);
            i++;
        }
    }
    swap(&nums[i], &nums[right]);
    return i;
}

int quickSelect(int* nums, int left, int right, int target) {
    if (left == right) return nums[left];

    int pivotIndex = partition(nums, left, right);

    if (pivotIndex == target) {
        return nums[pivotIndex];
    } else if (pivotIndex < target) {
        return quickSelect(nums, pivotIndex + 1, right, target);
    } else {
        return quickSelect(nums, left, pivotIndex - 1, target);
    }
}

int findKthLargest(int* nums, int numsSize, int k) {
    // k-th largest is (numsSize - k) index in a sorted array
    return quickSelect(nums, 0, numsSize - 1, numsSize - k);
}
