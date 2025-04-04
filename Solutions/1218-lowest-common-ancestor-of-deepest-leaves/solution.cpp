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
    int deepest(TreeNode* root, int d) {
        if(root == nullptr) return d;
        return max(deepest(root->left, d+1), deepest(root->right, d+1));
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        while(1) {
            int ld = deepest(root->left, 0);
            int rd = deepest(root->right, 0);
            if(ld == rd) return root;
            if(ld < rd) root = root->right;
            else root = root->left;
        }
    }
};
