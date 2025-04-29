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
    
    void trav(TreeNode* root, int level) {
        if(root == nullptr) return;
        ans = max(ans, level);
        trav(root->left, level+1);
        trav(root->right, level+1);
    }
    
    int maxDepth(TreeNode* root) {
        trav(root, 1);
        return ans;
    }
};
