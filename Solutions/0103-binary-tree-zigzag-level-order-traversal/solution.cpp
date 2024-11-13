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
    vector<vector<int>> ans;
    void traverse(TreeNode* root, int level) {
        if(root == nullptr) return;
        while(ans.size() < level) ans.push_back({});
        ans[level-1].push_back(root->val);
        traverse(root->left, level+1);
        traverse(root->right, level+1);
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        traverse(root, 1);
        for(int i = 1 ; i < ans.size(); i+=2) {
            reverse(ans[i].begin(), ans[i].end());
        }
        return ans;
    }
};
