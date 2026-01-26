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
    vector<long> sums;

    long tree_sum(TreeNode* root) {
        if(root == nullptr) return 0;
        long left = tree_sum(root->left);
        long right = tree_sum(root->right);
        long ans = root->val + left + right;
        sums.push_back(ans);
        return ans;
    }

    int maxProduct(TreeNode* root) {
        long total = tree_sum(root);
        long ans = 0;
        for(auto el : sums) {
            long local = (total - el) * el;
            ans = max(ans, local);
        }
        return ans % long(1e9 + 7);
    }
};
