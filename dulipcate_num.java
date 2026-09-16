class Solution {
    public int findDuplicate(int[] nums) {
        // Step 1: Initialize the tortoise and hare pointers
        int tortoise = nums[0];
        int hare = nums[0];
        
        // Step 2: Move hare twice as fast as tortoise to find the intersection point
        do {
            tortoise = nums[tortoise];
            hare = nums[nums[hare]];
        } while (tortoise != hare);
        
        // Step 3: Find the entrance to the cycle (the duplicate number)
        tortoise = nums[0];
        while (tortoise != hare) {
            tortoise = nums[tortoise];
            hare = nums[hare];
        }
        
        return tortoise;
    }
}
