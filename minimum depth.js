class Solution {
    public int minDepth(TreeNode root) {
        if (root == null) return 0;
        
        // If one child is null, we must take the path of the non-null child
        if (root.left == null) return minDepth(root.right) + 1;
        if (root.right == null) return minDepth(root.left) + 1;
        
        // If both exist, take the minimum of the two
        return Math.min(minDepth(root.left), minDepth(root.right)) + 1;
    }
}
