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

            // Get the next smallest node
            current = st.top();
            st.pop();

            k--;

            // If kth element is found
            if (k == 0) {
                return current->val;
            }

            // Move to right subtree
            current = current->right;
        }
    }
};
