class Solution {
    public int maxSubArray(int[] nums) {
        // Initialize with the first element
        int maxSoFar = nums[0];
        int currentMax = nums[0];

        for (int i = 1; i < nums.length; i++) {
            // Decide: extend the previous subarray or start a new one here?
            currentMax = Math.max(nums[i], currentMax + nums[i]);
            
            // Keep track of the best sum we've seen overall
            maxSoFar = Math.max(maxSoFar, currentMax);
        }

        return maxSoFar;
    }
}
