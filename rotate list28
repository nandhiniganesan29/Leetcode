class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        if (head == null || head.next == null || k == 0) return head;

        // 1. Compute length and find the actual tail
        ListNode oldTail = head;
        int length = 1;
        while (oldTail.next != null) {
            oldTail = oldTail.next;
            length++;
        }

        // 2. Connect tail to head to form a cycle
        oldTail.next = head;

        // 3. Find the new tail: (length - k % length) steps from the start
        ListNode newTail = head;
        for (int i = 0; i < length - (k % length) - 1; i++) {
            newTail = newTail.next;
        }

        // 4. Set the new head and break the cycle
        ListNode newHead = newTail.next;
        newTail.next = null;

        return newHead;
    }
}
