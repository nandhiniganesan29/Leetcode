/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// Helper to merge two sorted linked lists
struct ListNode* merge(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode dummy;
    struct ListNode* tail = &dummy;
    dummy.next = NULL;

    while (l1 && l2) {
        if (l1->val < l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    tail->next = l1 ? l1 : l2;
    return dummy.next;
}

struct ListNode* sortList(struct ListNode* head) {
    // Base case: 0 or 1 element is already sorted
    if (!head || !head->next) return head;

    // STEP 1: Split the list into two halves
    struct ListNode *prev = NULL, *slow = head, *fast = head;
    while (fast && fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    
    // Disconnect the first half from the second half
    prev->next = NULL;

    // STEP 2: Sort each half recursively
    struct ListNode* leftHalf = sortList(head);
    struct ListNode* rightHalf = sortList(slow);

    // STEP 3: Merge the sorted halves
    return merge(leftHalf, rightHalf);
}
