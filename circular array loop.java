class Solution {
    public boolean circularArrayLoop(int[] nums) {
        int n = nums.length;
        
        // Check every index as a potential starting point for a cycle
        for (int i = 0; i < n; i++) {
            // 0 means it's already visited and confirmed not to be part of a valid cycle
            if (nums[i] == 0) {
                continue;
            }
            
            int slow = i;
            int fast = i;
            // Determine direction: true for forward (+), false for backward (-)
            boolean isForward = nums[i] > 0;
            
            // Move slow and fast pointers
            while (true) {
                slow = getNextPosition(nums, slow, isForward);
                if (slow == -1) break; // Invalid movement or direction change
                
                fast = getNextPosition(nums, fast, isForward);
                if (fast == -1) break;
                
                fast = getNextPosition(nums, fast, isForward); // Fast moves twice
                if (fast == -1) break;
                
                if (slow == fast) {
                    // Check if the loop length is greater than 1
                    if (slow == getNextPosition(nums, slow, isForward)) {
                        break; // Loop of length 1 is invalid
                    }
                    return true;
                }
            }
            
            // Optimization: Mark all nodes in this failed path as 0 so we don't re-visit them
            int curr = i;
            while (nums[curr] != 0 && (nums[curr] > 0) == isForward) {
                int next = (curr + nums[curr] % n + n) % n;
                nums[curr] = 0;
                curr = next;
            }
        }
        
        return false;
    }
    
    // Helper function to calculate the next index and validate directions
    private int getNextPosition(int[] nums, int curr, boolean isForward) {
        int n = nums.length;
        // Check if the current direction matches the original direction
        if ((nums[curr] > 0) != isForward) {
            return -1;
        }
        
        // Handle circular index arithmetic (handles both positive and negative steps)
        int next = (curr + nums[curr] % n + n) % n;
        return next;
    }
}
