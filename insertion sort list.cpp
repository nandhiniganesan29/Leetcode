/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* insertionSortList(struct ListNode* head) {
    if (!head || !head->next) return head;

    // Create a dummy head for the new sorted list
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = NULL;
    
    struct ListNode* curr = head;

    while (curr != NULL) {
        // At each step, keep track of the next node to process
        struct ListNode* nextNode = curr->next;

        // Find the right position to insert 'curr' in the sorted list
        // We start from the dummy head for every insertion
        struct ListNode* prev = dummy;
        while (prev->next != NULL && prev->next->val < curr->val) {
            prev = prev->next;
        }

        // Insert 'curr' between 'prev' and 'prev->next'
        curr->next = prev->next;
        prev->next = curr;

        // Move to the next node in the original list
        curr = nextNode;
    }

    struct ListNode* sortedHead = dummy->next;
    free(dummy); // Clean up the dummy node
    return sortedHead;
}
