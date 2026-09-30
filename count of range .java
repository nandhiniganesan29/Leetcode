class Solution {
    public int countRangeSum(int[] nums, int lower, int upper) {
        int n = nums.length;
        // Step 1: Generate prefix sums array. 
        // Use 'long' to prevent integer overflow during summation.
        long[] prefixSums = new long[n + 1];
        for (int i = 0; i < n; i++) {
            prefixSums[i + 1] = prefixSums[i] + nums[i];
        }
        
        // Step 2: Use a modified merge sort to count combinations efficiently
        return mergeSortAndCount(prefixSums, 0, n, lower, upper);
    }
    
    private int mergeSortAndCount(long[] sums, int start, int end, int lower, int upper) {
        // Base case: a segment of length 1 cannot form a range sum pair
        if (start >= end) {
            return 0;
        }
        
        int mid = start + (end - start) / 2;
        
        // Count pairs entirely in the left half and entirely in the right half
        int count = mergeSortAndCount(sums, start, mid, lower, upper) 
                  + mergeSortAndCount(sums, mid + 1, end, lower, upper);
        
        // Count pairs where the left element is in the left sorted half, 
        // and the right element is in the right sorted half.
        int j = mid + 1; // Tracks the lower bound index satisfying: sums[j] - sums[i] >= lower
        int k = mid + 1; // Tracks the upper bound index satisfying: sums[k] - sums[i] <= upper
        
        for (int i = start; i <= mid; i++) {
            // Slide j forward until sums[j] - sums[i] >= lower
            while (j <= end && sums[j] - sums[i] < lower) {
                j++;
            }
            // Slide k forward until sums[k] - sums[i] > upper
            while (k <= end && sums[k] - sums[i] <= upper) {
                k++;
            }
            // The valid right elements for this specific sums[i] lie in the range [j, k)
            count += (k - j);
        }
        
        // Standard merge step to maintain the sorted order for subsequent steps
        merge(sums, start, mid, end);
        
        return count;
    }
    
    private void merge(long[] sums, int start, int mid, int end) {
        long[] temp = new long[end - start + 1];
        int i = start, j = mid + 1, p = 0;
        
        while (i <= mid && j <= end) {
            if (sums[i] <= sums[j]) {
                temp[p++] = sums[i++];
            } else {
                temp[p++] = sums[j++];
            }
        }
        
        while (i <= mid) {
            temp[p++] = sums[i++];
        }
        while (j <= end) {
            temp[p++] = sums[j++];
        }
        
        System.arraycopy(temp, 0, sums, start, temp.length);
    }
}
