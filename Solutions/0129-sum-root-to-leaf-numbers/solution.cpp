/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        stack<pair<TreeNode*, int>> st;
        st.push(make_pair(root, root->val));
        while(!st.empty()) {
            auto mmd = st.top(); st.pop();
            TreeNode* curr = mmd.first; int so_far = mmd.second;
            if(curr->left == nullptr && curr->right == nullptr) {
                // leaf!
                ans += so_far;
            }
            if(curr->left != nullptr) {
                st.push(make_pair(curr->left, so_far * 10 + curr->left->val));
            }
            if(curr->right != nullptr) {
                st.push(make_pair(curr->right, so_far * 10 + curr->right->val));
            }
        }
        return ans;
    }
};
