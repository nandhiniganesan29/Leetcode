#include <stdlib.h>

struct TreeNode* helper(int* inorder, int inStart, int inEnd, 
                        int* postorder, int postStart, int postEnd) {
    // Base case: if the range is invalid, return NULL
    if (inStart > inEnd || postStart > postEnd) return NULL;

    // 1. The last element in postorder is the root
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = postorder[postEnd];
    
    // 2. Find the index of the root in the inorder array
    int rootIdx = inStart;
    while (inorder[rootIdx] != root->val) {
        rootIdx++;
    }

    // 3. Calculate the size of the left subtree
    int leftSize = rootIdx - inStart;

    // 4. Recursively build right and left subtrees
    // Left: use 'leftSize' elements from the start of postorder.
    root->left = helper(inorder, inStart, rootIdx - 1, 
                        postorder, postStart, postStart + leftSize - 1);
    
    // Right: skip the root (at postEnd) and the left elements.
    root->right = helper(inorder, rootIdx + 1, inEnd, 
                         postorder, postStart + leftSize, postEnd - 1);

    return root;
}

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
    return helper(inorder, 0, inorderSize - 1, postorder, 0, postorderSize - 1);
}
