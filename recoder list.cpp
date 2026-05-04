/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void reorderList(struct ListNode* head) {
    if (!head || !head->next || !head->next->next) return;

    // STEP 1: Find the middle of the list
    struct ListNode *slow = head, *fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // STEP 2: Reverse the second half of the list
    struct ListNode *prev = NULL, *curr = slow->next, *next = NULL;
    slow->next = NULL; // Terminate the first half
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    struct ListNode *secondHalf = prev; // The new head of reversed half

    // STEP 3: Merge the two halves
    struct ListNode *firstHalf = head;
    while (secondHalf) {
        struct ListNode *temp1 = firstHalf->next;
        struct ListNode *temp2 = secondHalf->next;

        firstHalf->next = secondHalf;
        secondHalf->next = temp1;

        firstHalf = temp1;
        secondHalf = temp2;
    }
}
