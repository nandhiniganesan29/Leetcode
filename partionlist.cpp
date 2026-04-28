/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* partition(struct ListNode* head, int x) {
    // Dummy nodes to simplify head management for both chains
    struct ListNode lessHead, greaterHead;
    struct ListNode *less = &lessHead, *greater = &greaterHead;

    lessHead.next = NULL;
    greaterHead.next = NULL;

    while (head != NULL) {
        if (head->val < x) {
            less->next = head;
            less = less->next;
        } else {
            greater->next = head;
            greater = greater->next;
        }
        head = head->next;
    }

    // Terminate the greater chain to avoid cycles
    greater->next = NULL;
    // Connect the 'less' chain to the 'greater' chain
    less->next = greaterHead.next;

    return lessHead.next;
}
