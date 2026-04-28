/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    if (head == NULL || left == right) return head;

    // Use a dummy node to handle the case where left = 1
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* prev = &dummy;

    // 1. Move 'prev' to the node just before the reversal starts
    for (int i = 0; i < left - 1; i++) {
        prev = prev->next;
    }

    // 2. 'start' is the first node of the segment to be reversed
    // 'then' is the node that will be moved to the front of the segment
    struct ListNode* start = prev->next;
    struct ListNode* then = start->next;

    // 3. Perform the reversal in-place
    // We move 'then' to the position after 'prev' one by one
    for (int i = 0; i < right - left; i++) {
        start->next = then->next;
        then->next = prev->next;
        prev->next = then;
        then = start->next;
    }

    return dummy.next;
}
