/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    if (head == NULL || head->next == NULL) {
        return false;
    }

    struct ListNode *slow = head;
    struct ListNode *fast = head;

    // Fast pointer moves twice as fast as the slow pointer
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        // If there is a cycle, the fast pointer will eventually catch up to the slow one
        if (slow == fast) {
            return true;
        }
    }

    // If fast reaches the end, there is no cycle
    return false;
}
