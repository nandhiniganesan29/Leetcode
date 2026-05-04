#include <math.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int maxProduct(int* nums, int numsSize) {
    if (numsSize == 0) return 0;

    int max_so_far = nums[0];
    int min_so_far = nums[0];
    int result = nums[0];

    for (int i = 1; i < numsSize; i++) {
        int curr = nums[i];
        
        // When curr is negative, max and min swap roles
        if (curr < 0) {
            int temp = max_so_far;
            max_so_far = min_so_far;
            min_so_far = temp;
        }

        // Decide whether to start a new subarray or extend the existing one
        max_so_far = MAX(curr, max_so_far * curr);
        min_so_far = MIN(curr, min_so_far * curr);

        result = MAX(result, max_so_far);
    }

    return result;
}
