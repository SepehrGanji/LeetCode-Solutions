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
    int depans = 0;
    
    void dfs(TreeNode* root, int level) {
        if(root == nullptr) return;
        if(root->right == nullptr && root->left == nullptr) {
            if(level == depans) ans += root->val;
            return;
        }
        dfs(root->right, level+1);
        dfs(root->left, level+1);
    }
    
    void deepest(TreeNode* root, int level) {
        if(root == nullptr) return;
        if(root->right == nullptr && root->left == nullptr) {
            depans = max(depans, level);
            return;
        }
        deepest(root->right, level+1);
        deepest(root->left, level+1);
    }
    
    int deepestLeavesSum(TreeNode* root) {
        deepest(root, 0);
        dfs(root, 0);
        return ans;
    }
};
