class Solution {
    public boolean hasPathSum(TreeNode root, int targetSum) {
        // Base case: if the tree is empty, no path exists
        if (root == null) {
            return false;
        }

        // Check if we are at a leaf node (no children)
        if (root.left == null && root.right == null) {
            return targetSum == root.val;
        }

        // Recursively check left and right subtrees with the updated sum
        int remainingSum = targetSum - root.val;
        return hasPathSum(root.left, remainingSum) || 
               hasPathSum(root.right, remainingSum);
    }
}
