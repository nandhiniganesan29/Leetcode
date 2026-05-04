/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int calculateSum(struct TreeNode* node, int currentSum) {
    if (node == NULL) {
        return 0;
    }

    // Update the running sum for the current path
    currentSum = currentSum * 10 + node->val;

    // Check if it's a leaf node
    if (node->left == NULL && node->right == NULL) {
        return currentSum;
    }

    // Recurse for left and right children and return their total
    return calculateSum(node->left, currentSum) + calculateSum(node->right, currentSum);
}

int sumNumbers(struct TreeNode* root) {
    return calculateSum(root, 0);
}
