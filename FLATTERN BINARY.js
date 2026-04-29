class Solution {
    private TreeNode last = null;

    public void flatten(TreeNode root) {
        if (root == null) return;

        // Traverse in reverse: Right, then Left, then Root
        flatten(root.right);
        flatten(root.left);

        // Set the right child to the node we processed "last"
        root.right = last;
        // The left child must be null in the flattened version
        root.left = null;
        
        // Move the "last" pointer to the current node
        last = root;
    }
}
