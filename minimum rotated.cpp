int findMin(int* nums, int numsSize) {
    // Assume the first element is the minimum
    int min = nums[0];

    // Iterate through the array starting from the second element
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] < min) {
            min = nums[i];
        }
    }
    return min;
}
