#include <stdlib.h>

struct TreeNode* sortedListToBST(struct ListNode* head) {
    // Base Case: Empty list
    if (head == NULL) return NULL;
    
    // Base Case: Single node (prevents infinite recursion)
    if (head->next == NULL) {
        struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        root->val = head->val;
        root->left = root->right = NULL;
        return root;
    }

    // 1. Find the middle node and the node preceding it
    struct ListNode *slow = head, *fast = head, *prev = NULL;
    while (fast != NULL && fast->next != NULL) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    // 2. Disconnect the left half from the middle node
    if (prev != NULL) prev->next = NULL;

    // 3. Create root from middle (slow)
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = slow->val;

    // 4. Recursively build subtrees
    // The head now points to a shorter list (up to prev)
    root->left = sortedListToBST(head);
    // The right half starts from the node after the middle
    root->right = sortedListToBST(slow->next);

    return root;
}
