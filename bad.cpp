// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1;
        int right = n;
        
        while (left < right) {
            // Prevents integer overflow that (left + right) / 2 might cause
            int mid = left + (right - left) / 2; 
            
            if (isBadVersion(mid)) {
                // If mid is bad, the first bad version is either mid or before mid
                right = mid;
            } else {
                // If mid is good, the first bad version must be after mid
                left = mid + 1;
            }
        }
        
        // When left == right, we have found the first bad version
        return left;
    }
};
