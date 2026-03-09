class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
        
        ListNode curr = head;
        int count = 0;

        // Check if there are at least k nodes
        while (curr != null && count < k) {
            curr = curr.next;
            count++;
        }

        // If we have k nodes, reverse them
        if (count == k) {
            curr = reverseKGroup(curr, k); // Reverse next groups

            while (count > 0) {
                ListNode next = head.next;
                head.next = curr;
                curr = head;
                head = next;
                count--;
            }
            head = curr;
        }

        return head;
    }
}
