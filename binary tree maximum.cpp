#include <limits.h>
#include <math.h>

// Helper function to find the max of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Recursive helper to calculate gain and update global maximum
int calculateGain(struct TreeNode* node, int* maxSum) {
    if (node == NULL) return 0;

    // Recursively get the max path sum from children
    // If a path sum is negative, we ignore it (take 0)
    int leftGain = max(calculateGain(node->left, maxSum), 0);
    int rightGain = max(calculateGain(node->right, maxSum), 0);

    // Price of the new path including the current node as the "highest" point
    int currentPathSum = node->val + leftGain + rightGain;

    // Update the global maximum if the current path is better
    if (currentPathSum > *maxSum) {
        *maxSum = currentPathSum;
    }

    // Return the max gain this node can contribute to its parent
    return node->val + max(leftGain, rightGain);
}

int maxPathSum(struct TreeNode* root) {
    int maxSum = INT_MIN;
    calculateGain(root, &maxSum);
    return maxSum;
}
