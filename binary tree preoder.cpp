#include <stdlib.h>

/**
 * Helper to count total nodes in the tree
 */
int getSize(struct TreeNode* root) {
    if (!root) return 0;
    return 1 + getSize(root->left) + getSize(root->right);
}

/**
 * Recursive helper to fill the array in Preorder
 */
void helper(struct TreeNode* node, int* res, int* pos) {
    if (!node) return;
    
    // 1. Visit Root
    res[(*pos)++] = node->val;
    // 2. Traverse Left
    helper(node->left, res, pos);
    // 3. Traverse Right
    helper(node->right, res, pos);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int size = getSize(root);
    *returnSize = size;
    
    int* result = (int*)malloc(size * sizeof(int));
    if (size == 0) return result;

    int pos = 0;
    helper(root, result, &pos);
    
    return result;
}
