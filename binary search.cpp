#include <stdbool.h>
#include <stdlib.h>

/**
 * Definition for a binary tree node.
 */
// struct TreeNode {
//     int val;
//     struct TreeNode *left;
//     struct TreeNode *right;
// };

typedef struct {
    struct TreeNode** stack;
    int top;
} BSTIterator;

/** 
 * Helper function to push a node and all of its left children 
 * onto the stack. This ensures the smallest value is at the top.
 */
void pushLeft(BSTIterator* obj, struct TreeNode* node) {
    while (node != NULL) {
        obj->stack[++(obj->top)] = node;
        node = node->left;
    }
}

BSTIterator* bSTIteratorCreate(struct TreeNode* root) {
    BSTIterator* obj = (BSTIterator*)malloc(sizeof(BSTIterator));
    // Based on constraints (10^5 nodes), max height could be 10^5 in a skewed tree.
    obj->stack = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 100001);
    obj->top = -1;
    pushLeft(obj, root);
    return obj;
}

/** 
 * Average O(1) time: each node is pushed and popped exactly once.
 */
int bSTIteratorNext(BSTIterator* obj) {
    // 1. Pop the top (smallest available node)
    struct TreeNode* node = obj->stack[(obj->top)--];
    
    // 2. If it has a right child, the next smallest value is in its left branch
    if (node->right != NULL) {
        pushLeft(obj, node->right);
    }
    
    return node->val;
}

/** 
 * O(1) time.
 */
bool bSTIteratorHasNext(BSTIterator* obj) {
    return obj->top != -1;
}

void bSTIteratorFree(BSTIterator* obj) {
    free(obj->stack);
    free(obj);
}
