/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode oddEvenList(ListNode head) {
        // Base case: if the list is empty or has only one node, no rearrangement is needed
        if (head == null || head.next == null) {
            return head;
        }

        // 'odd' tracks the current node in the odd chain
        ListNode odd = head;
        // 'even' tracks the current node in the even chain
        ListNode even = head.next;
        // Keep a reference to the head of the even chain to connect it later
        ListNode evenHead = even;

        // Traverse the list until we run out of even nodes
        while (even != null && even.next != null) {
            odd.next = even.next;    // Connect current odd node to the next odd node
            odd = odd.next;          // Move the odd pointer forward
            
            even.next = odd.next;    // Connect current even node to the next even node
            even = even.next;        // Move the even pointer forward
        }

        // Attach the beginning of the even list to the end of the odd list
        odd.next = evenHead;

        return head;
    }
}
