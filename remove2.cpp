struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (!head) return NULL;

    // Dummy node points to head to handle head deletions easily
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* prev = &dummy;

    while (head) {
        // If it's a start of a duplicate sequence
        if (head->next && head->val == head->next->val) {
            // Move head to the end of the duplicate sequence
            while (head->next && head->val == head->next->val) {
                head = head->next;
            }
            // Skip all duplicates by linking prev to the node after the sequence
            prev->next = head->next;
        } else {
            // No duplicate, move prev forward
            prev = prev->next;
        }
        // Move head forward for the next iteration
        head = head->next;
    }

    return dummy.next;
}
