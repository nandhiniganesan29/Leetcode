void sortColors(int* nums, int numsSize) {
    int low = 0;           // Boundary for 0s
    int mid = 0;           // Current element under consideration
    int high = numsSize - 1; // Boundary for 2s

    while (mid <= high) {
        if (nums[mid] == 0) {
            // Found a 0: Swap with the low pointer and move both forward
            int temp = nums[low];
            nums[low] = nums[mid];
            nums[mid] = temp;
            low++;
            mid++;
        } else if (nums[mid] == 1) {
            // Found a 1: It's in the right place for now, just move mid forward
            mid++;
        } else { // nums[mid] == 2
            // Found a 2: Swap with the high pointer and move high backward
            // Do NOT move mid forward yet, because the swapped element 
            // from 'high' needs to be checked.
            int temp = nums[high];
            nums[high] = nums[mid];
            nums[mid] = temp;
            high--;
        }
    }
}
