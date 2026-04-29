class Solution {
    public Node connect(Node root) {
        if (root == null) return null;
        
        Node curr = root;
        
        // While there is a next level to connect
        while (curr.left != null) {
            Node temp = curr;
            
            while (temp != null) {
                // Connection 1: Connect the two children of the same parent
                temp.left.next = temp.right;
                
                // Connection 2: Connect the right child to the left child of the next parent
                if (temp.next != null) {
                    temp.right.next = temp.next.left;
                }
                
                // Move across the current level
                temp = temp.next;
            }
            
            // Move down to the start of the next level
            curr = curr.left;
        }
        
        return root;
    }
}
