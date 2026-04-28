#include <stdbool.h>

bool search(int* nums, int numsSize, int target) {
    int low = 0, high = numsSize - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] == target) return true;

        // The critical addition for duplicates:
        // If low, mid, and high are all the same, we can't tell which side is sorted.
        // We just shrink the boundaries and continue.
        if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
            low++;
            high--;
        } 
        // Left side is sorted
        else if (nums[low] <= nums[mid]) {
            if (target >= nums[low] && target < nums[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        } 
        // Right side is sorted
        else {
            if (target > nums[mid] && target <= nums[high]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }

    return false;
}
