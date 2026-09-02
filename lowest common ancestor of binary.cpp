class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        // If root is NULL or root is one of p or q
        if (root == nullptr || root == p || root == q) {
            return root;
        }

        // Search in left and right subtrees
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // If p and q are found on different sides
        if (left != nullptr && right != nullptr) {
            return root;
        }

        // Return whichever side contains a node
        if (left != nullptr)
            return left;

        return right;
    }
};
