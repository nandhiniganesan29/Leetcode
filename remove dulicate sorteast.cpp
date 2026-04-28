int removeDuplicates(int* nums, int numsSize) {
    if (numsSize <= 2) return numsSize;

    // k is the pointer for the next valid position in the modified array
    int k = 2; 

    for (int i = 2; i < numsSize; i++) {
        // Compare current element with the element two positions before the insertion point
        // If they are different, it means we haven't reached three of a kind yet
        if (nums[i] != nums[k - 2]) {
            nums[k] = nums[i];
            k++;
        }
    }

    return k;
}
