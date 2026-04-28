#include <stdlib.h>

/**
 * Helper function to build the tree recursively.
 */
struct TreeNode* buildBST(int* nums, int left, int right) {
    if (left > right) {
        return NULL;
    }

    // Pick the middle element as the root to maintain balance
    int mid = left + (right - left) / 2;
    
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = nums[mid];
    
    // Recursively build left and right subtrees using the split array
    root->left = buildBST(nums, left, mid - 1);
    root->right = buildBST(nums, mid + 1, right);
    
    return root;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    if (numsSize == 0) return NULL;
    return buildBST(nums, 0, numsSize - 1);
}
