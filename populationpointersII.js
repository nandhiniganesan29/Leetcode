class Solution {
    public Node connect(Node root) {
        Node curr = root; // The node we are currently at in the "parent" level
        
        while (curr != null) {
            Node dummy = new Node(0); // Temporary head for the "child" level
            Node tail = dummy;        // Current end of the "child" level list
            
            // Traverse the current level and link its children
            while (curr != null) {
                if (curr.left != null) {
                    tail.next = curr.left;
                    tail = tail.next;
                }
                if (curr.right != null) {
                    tail.next = curr.right;
                    tail = tail.next;
                }
                // Move to the next node in the current parent level
                curr = curr.next;
            }
            
            // Move down to the first node of the child level we just linked
            curr = dummy.next;
        }
        
        return root;
    }
}
