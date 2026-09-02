class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        TreeNode* current = root;

        while (true) {
            // Go to the leftmost node
            while (current != nullptr) {
                st.push(current);
                current = current->left;
            }

            // Get the next smallest element
            current = st.top();
            st.pop();

            k--;

            if (k == 0) {
                return current->val;
            }

            // Move to the right subtree
            current = current->right;
        }
    }
};
