int singleNumber(int* nums, int numsSize) {
    int ones = 0; // Bits that have appeared once (mod 3 == 1)
    int twos = 0; // Bits that have appeared twice (mod 3 == 2)

    for (int i = 0; i < numsSize; i++) {
        // Update 'ones':
        // Keep bits that were already in 'ones' OR are new from nums[i],
        // but ONLY if they are NOT already in 'twos'.
        ones = (ones ^ nums[i]) & ~twos;

        // Update 'twos':
        // Keep bits that were already in 'twos' OR are moving from 'ones',
        // but ONLY if they are NOT already in the new 'ones'.
        twos = (twos ^ nums[i]) & ~ones;
    }

    // After processing, bits appearing 3 times reset to 0 in both.
    // The number appearing exactly once is stored in 'ones'.
    return ones;
}
