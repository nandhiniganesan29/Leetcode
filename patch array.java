class Solution {
    public int minPatches(int[] nums, int n) {
        // 'miss' represents the smallest integer that cannot be formed yet.
        // We use 'long' to prevent integer overflow when adding up numbers.
        long miss = 1;
        int patches = 0;
        int i = 0;

        // Keep extending our range until we can cover up to 'n'
        while (miss <= n) {
            // Case 1: The current element in nums is within our reachable capability
            if (i < nums.length && nums[i] <= miss) {
                // By including nums[i], our reachable range expands from [1, miss-1] to [1, miss + nums[i] - 1]
                miss += nums[i];
                i++;
            } 
            // Case 2: There is a gap, meaning nums[i] is too big or we've run out of elements
            else {
                // Greedily patch the array by adding 'miss' itself
                // This maximizes the range extension to [1, miss + miss - 1]
                miss += miss;
                patches++;
            }
        }

        return patches;
    }
}
