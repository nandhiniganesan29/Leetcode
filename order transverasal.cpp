#include <stdlib.h>

int getHeight(struct TreeNode* root) {
    if (!root) return 0;
    int lh = getHeight(root->left);
    int rh = getHeight(root->right);
    return (lh > rh ? lh : rh) + 1;
}

int** levelOrderBottom(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if (!root) {
        *returnSize = 0;
        return NULL;
    }

    int height = getHeight(root);
    *returnSize = height;
    int** result = (int**)malloc(height * sizeof(int*));
    *returnColumnSizes = (int*)malloc(height * sizeof(int));

    // Queue for standard BFS
    struct TreeNode** queue = (struct TreeNode**)malloc(2000 * sizeof(struct TreeNode*));
    int head = 0, tail = 0;
    queue[tail++] = root;

    // Fill levels normally (Top-to-Bottom)
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

    // Reverse the result and columnSizes to get Bottom-Up
    for (int i = 0; i < height / 2; i++) {
        // Swap level arrays
        int* tempLevel = result[i];
        result[i] = result[height - 1 - i];
        result[height - 1 - i] = tempLevel;

        // Swap column sizes
        int tempSize = (*returnColumnSizes)[i];
        (*returnColumnSizes)[i] = (*returnColumnSizes)[height - 1 - i];
        (*returnColumnSizes)[height - 1 - i] = tempSize;
    }

    free(queue);
    return result;
}
