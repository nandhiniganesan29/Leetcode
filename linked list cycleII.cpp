/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    if (head == NULL || head->next == NULL) return NULL;

    struct ListNode *slow = head;
    struct ListNode *fast = head;

    // PHASE 1: Detect if a cycle exists
    bool hasCycle = false;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            hasCycle = true;
            break;
        }
    }

    // If no cycle was found, return NULL
    if (!hasCycle) return NULL;

    // PHASE 2: Find the entry point of the cycle
    // Reset slow to head; keep fast at the meeting point.
    // Move both at the same speed (1 step). They will meet at the start.
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}
