#include <stdbool.h>

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    // If both nodes are NULL, they are identical
    if (p == NULL && q == NULL) {
        return true;
    }
    
    // If one is NULL but the other isn't, they are different
    if (p == NULL || q == NULL) {
        return false;
    }
    
    // Values must match, and their subtrees must also be the same
    return (p->val == q->val) && 
           isSameTree(p->left, q->left) && 
           isSameTree(p->right, q->right);
}
