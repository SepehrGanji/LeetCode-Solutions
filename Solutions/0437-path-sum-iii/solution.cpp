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
    int ans;
    int tar;
    unordered_map<long, int> cnt;

    void traverse(TreeNode* root, long curr) {
        if(root == nullptr) return;
        curr += root->val;
        ans += cnt[curr-tar];
        cnt[curr]++;
        traverse(root->left, curr);
        traverse(root->right, curr);
        cnt[curr]--;
    }

    int pathSum(TreeNode* root, int targetSum) {
        cnt[0] = 1;
        tar = targetSum;
        traverse(root, 0);
        return ans;
    }
};
