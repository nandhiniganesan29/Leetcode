#include <stdlib.h>

struct TreeNode* helper(int* preorder, int preStart, int preEnd, 
                        int* inorder, int inStart, int inEnd) {
    if (preStart > preEnd || inStart > inEnd) return NULL;

    // 1. The first element in preorder is the root
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = preorder[preStart];
    
    // 2. Find the index of the root in the inorder array
    int rootIdx = inStart;
    while (inorder[rootIdx] != root->val) {
        rootIdx++;
    }

    // 3. Calculate the size of the left subtree
    int leftSize = rootIdx - inStart;

    // 4. Recursively build left and right subtrees
    // Left: Skip root in preorder; take 'leftSize' elements. In inorder, use elements before rootIdx.
    root->left = helper(preorder, preStart + 1, preStart + leftSize, 
                        inorder, inStart, rootIdx - 1);
    
    // Right: Skip root and left elements in preorder. In inorder, use elements after rootIdx.
    root->right = helper(preorder, preStart + leftSize + 1, preEnd, 
                         inorder, rootIdx + 1, inEnd);

    return root;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    return helper(preorder, 0, preorderSize - 1, inorder, 0, inorderSize - 1);
}
