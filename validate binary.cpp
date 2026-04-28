#include <stdbool.h>
#include <limits.h>

/**
 * Helper function to validate nodes within a specific range.
 * We use long long to handle the edge case of INT_MIN and INT_MAX values.
 */
bool validate(struct TreeNode* node, long long min, long long max) {
    if (node == NULL) {
        return true;
    }

    // The current node's value must be strictly between min and max
    if (node->val <= min || node->val >= max) {
        return false;
    }

    // Left child must be < node->val
    // Right child must be > node->val
    return validate(node->left, min, node->val) && 
           validate(node->right, node->val, max);
}

bool isValidBST(struct TreeNode* root) {
    // Start with the widest possible range
    return validate(root, LLONG_MIN, LLONG_MAX);
}
