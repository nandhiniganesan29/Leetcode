#include <stdlib.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    if (root == NULL) return NULL;

    // Allocate memory for the result array and a manual stack
    // In a real scenario, you'd count nodes first or use a dynamic array
    int* res = (int*)malloc(2000 * sizeof(int)); 
    struct TreeNode** stack = (struct TreeNode**)malloc(2000 * sizeof(struct TreeNode*));
    int top = -1;
    
    struct TreeNode* curr = root;

    while (curr != NULL || top != -1) {
        // 1. Reach the leftmost node of the current subtree
        while (curr != NULL) {
            stack[++top] = curr;
            curr = curr->left;
        }

        // 2. Process the node
        curr = stack[top--];
        res[(*returnSize)++] = curr->val;

        // 3. Move to the right subtree
        curr = curr->right;
    }

    free(stack);
    return res;
}
