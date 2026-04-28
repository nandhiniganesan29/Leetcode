#include <stdlib.h>

struct TreeNode *first, *second, *prev;

void findSegments(struct TreeNode* root) {
    if (!root) return;

    findSegments(root->left);

    // Identify the swapped nodes
    if (prev != NULL && root->val < prev->val) {
        // First occurrence: 'prev' is the larger node that was swapped
        if (first == NULL) first = prev;
        // Second occurrence (or same as first): 'root' is the smaller node
        second = root;
    }
    prev = root;

    findSegments(root->right);
}

void recoverTree(struct TreeNode* root) {
    first = second = prev = NULL;
    
    // Find the two swapped nodes using in-order traversal
    findSegments(root);
    
    // Swap the values back
    if (first && second) {
        int temp = first->val;
        first->val = second->val;
        second->val = temp;
    }
}
