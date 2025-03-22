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
    void leafSec(TreeNode* root, vector<int> &ans) {
        if(root == nullptr) return;
        if(root->left == nullptr && root->right == nullptr) {
            ans.push_back(root->val);
            return;
        }
        leafSec(root->left, ans);
        leafSec(root->right, ans);
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> seq1, seq2;
        leafSec(root1, seq1);
        leafSec(root2, seq2);
        int n = seq1.size(), m = seq2.size();
        if(n != m) return false;
        for(int i = 0 ; i < n ; i++) {
            if(seq1[i] != seq2[i]) return false;
        }
        return true;
    }
};
