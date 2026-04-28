#include <math.h>

int maxDepth(struct TreeNode* root) {
    // Base case: an empty tree has a depth of 0
    if (root == NULL) {
        return 0;
    }

    // Recursively find the depth of left and right subtrees
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);

    // The current depth is 1 + the greater of the two subtrees
    return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
}
