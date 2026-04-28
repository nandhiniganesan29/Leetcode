class Solution {
    public int mySqrt(int x) {
        // Base cases: sqrt(0) is 0 and sqrt(1) is 1
        if (x < 2) {
            return x;
        }

        int left = 1;
        int right = x / 2; // The square root of x is always <= x/2 for x >= 2
        int ans = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2; // Avoid potential (left + right) overflow
            
            // Check if mid * mid <= x using division to avoid overflow
            if (mid <= x / mid) {
                ans = mid;      // mid could be the answer
                left = mid + 1; // look for a larger value
            } else {
                right = mid - 1; // mid is too large
            }
        }

        return ans;
    }
}
