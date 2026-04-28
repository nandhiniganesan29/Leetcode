#include <stdlib.h>

/**
 * Helper function to create a new TreeNode.
 */
struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

/**
 * Recursive function to generate all unique BSTs in range [start, end].
 */
struct TreeNode** buildTrees(int start, int end, int* returnSize) {
    if (start > end) {
        *returnSize = 1;
        struct TreeNode** res = (struct TreeNode**)malloc(sizeof(struct TreeNode*));
        res[0] = NULL;
        return res;
    }

    int totalTrees = 0;
    // Calculate space needed for results (optional: can also use a dynamic array)
    // For n nodes, the number of unique BSTs is the nth Catalan number.
    struct TreeNode** all_trees = NULL;
    int currentCount = 0;

    for (int i = start; i <= end; i++) {
        int leftSize, rightSize;
        struct TreeNode** leftSubtrees = buildTrees(start, i - 1, &leftSize);
        struct TreeNode** rightSubtrees = buildTrees(i + 1, end, &rightSize);

        // Combine every left subtree with every right subtree for root 'i'
        int combinedSize = leftSize * rightSize;
        all_trees = (struct TreeNode**)realloc(all_trees, (currentCount + combinedSize) * sizeof(struct TreeNode*));

        for (int j = 0; j < leftSize; j++) {
            for (int k = 0; k < rightSize; k++) {
                struct TreeNode* root = createNode(i);
                root->left = leftSubtrees[j];
                root->right = rightSubtrees[k];
                all_trees[currentCount++] = root;
            }
        }
        // Free the temporary subtree arrays, but not the nodes themselves
        free(leftSubtrees);
        free(rightSubtrees);
    }

    *returnSize = currentCount;
    return all_trees;
}

struct TreeNode** generateTrees(int n, int* returnSize) {
    if (n == 0) {
        *returnSize = 0;
        return NULL;
    }
    return buildTrees(1, n, returnSize);
}
