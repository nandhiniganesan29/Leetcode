class Solution {
    public int jump(int[] nums) {
        int jumps = 0;
        int currentEnd = 0;
        int farthest = 0;

        // We don't need to jump if we are already at the last index
        // So we loop until n - 1
        for (int i = 0; i < nums.length - 1; i++) {
            // Update the farthest point we can reach from the current index
            farthest = Math.max(farthest, i + nums[i]);

            // If we have reached the end of the range for the current jump
            if (i == currentEnd) {
                jumps++;
                currentEnd = farthest;

                // Optimization: if we can already reach the end, break early
                if (currentEnd >= nums.length - 1) {
                    break;
                }
            }
        }

        return jumps;
    }
}
