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
    int ans = 0;

    void travel(TreeNode* root, int par, int window) {
        ans = max(ans, window);
        if(root == nullptr) return;

        if(root->val == par + 1) window++;
        else window = 1;
        
        travel(root->left, root->val, window);
        travel(root->right, root->val, window);
    }

    int longestConsecutive(TreeNode* root) {
        travel(root, root->val-10, 0);
        return ans;
    }
};
