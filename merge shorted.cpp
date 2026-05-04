void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int p1 = m - 1;
    int p2 = n - 1;
    int p = m + n - 1;

    while (p1 >= 0 && p2 >= 0) {
        // Post-decrement happens after the assignment
        nums1[p--] = (nums1[p1] > nums2[p2]) ? nums1[p1--] : nums2[p2--];
    }

    // Only need to catch nums2; if nums1 has elements left, they are already "home"
    while (p2 >= 0) {
        nums1[p--] = nums2[p2--];
    }
}
