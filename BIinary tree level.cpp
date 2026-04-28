#include <stdlib.h>

/**
 * Helper to get the height of the tree for memory allocation.
 */
int getHeight(struct TreeNode* root) {
    if (!root) return 0;
    int lh = getHeight(root->left);
    int rh = getHeight(root->right);
    return (lh > rh ? lh : rh) + 1;
}

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if (!root) {
        *returnSize = 0;
        return NULL;
    }

    int height = getHeight(root);
    *returnSize = height;
    
    int** result = (int**)malloc(height * sizeof(int*));
    *returnColumnSizes = (int*)malloc(height * sizeof(int));

    // Simple Queue for BFS
    struct TreeNode** queue = (struct TreeNode**)malloc(2000 * sizeof(struct TreeNode*));
    int head = 0, tail = 0;
    queue[tail++] = root;

    for (int i = 0; i < height; i++) {
        int levelSize = tail - head;
        (*returnColumnSizes)[i] = levelSize;
        result[i] = (int*)malloc(levelSize * sizeof(int));

        for (int j = 0; j < levelSize; j++) {
            struct TreeNode* node = queue[head++];
            result[i][j] = node->val;

            if (node->left) queue[tail++] = node->left;
            if (node->right) queue[tail++] = node->right;
        }
    }

    free(queue);
    return result;
}
