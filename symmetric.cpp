#include <stdbool.h>

/**
 * Helper function to check if two trees are mirrors of each other.
 */
bool isMirror(struct TreeNode* t1, struct TreeNode* t2) {
    // Both are empty
    if (t1 == NULL && t2 == NULL) return true;
    
    // One is empty, or values don't match
    if (t1 == NULL || t2 == NULL || t1->val != t2->val) return false;

    // Check mirrors: 
    // t1's left vs t2's right AND t1's right vs t2's left
    return isMirror(t1->left, t2->right) && isMirror(t1->right, t2->left);
}

bool isSymmetric(struct TreeNode* root) {
    if (root == NULL) return true;
    return isMirror(root->left, root->right);
}
