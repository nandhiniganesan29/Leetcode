int singleNumber(int* nums, int numsSize) {
    int ones = 0; // Bits that have appeared once
    int twos = 0; // Bits that have appeared twice

    for (int i = 0; i < numsSize; i++) {
        // "ones" will keep bits that appeared 1st time or 4th time...
        // but we filter out those that are in "twos"
        ones = (ones ^ nums[i]) & ~twos;

        // "twos" will keep bits that appeared 2nd time or 5th time...
        // but we filter out those that are in "ones"
        twos = (twos ^ nums[i]) & ~ones;
    }

    return ones;
}
