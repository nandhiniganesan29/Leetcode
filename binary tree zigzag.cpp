#include <stdlib.h>
#include <stdbool.h>

int getHeight(struct TreeNode* root) {
    if (!root) return 0;
    int lh = getHeight(root->left);
    int rh = getHeight(root->right);
    return (lh > rh ? lh : rh) + 1;
}

int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if (!root) {
        *returnSize = 0;
        return NULL;
    }

    int height = getHeight(root);
    *returnSize = height;
    int** result = (int**)malloc(height * sizeof(int*));
    *returnColumnSizes = (int*)malloc(height * sizeof(int));

    // Queue for BFS (using a safe upper bound for node count)
    struct TreeNode** queue = (struct TreeNode**)malloc(2000 * sizeof(struct TreeNode*));
    int head = 0, tail = 0;
    queue[tail++] = root;

    bool reverse = false;

    for (int i = 0; i < height; i++) {
        int levelSize = tail - head;
        (*returnColumnSizes)[i] = levelSize;
        result[i] = (int*)malloc(levelSize * sizeof(int));

        for (int j = 0; j < levelSize; j++) {
            struct TreeNode* node = queue[head++];
            
            // If reverse is true, fill from end to start, else start to end
            int index = reverse ? (levelSize - 1 - j) : j;
            result[i][index] = node->val;

            if (node->left) queue[tail++] = node->left;
            if (node->right) queue[tail++] = node->right;
        }
        // Toggle direction for the next level
        reverse = !reverse;
    }

    free(queue);
    return result;
}
