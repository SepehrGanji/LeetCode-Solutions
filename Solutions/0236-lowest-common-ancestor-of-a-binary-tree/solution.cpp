/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool findme(TreeNode* root, int el) {
        if(root == nullptr) return false;
        if(root->val == el) return true;
        return findme(root->left, el) || findme(root->right, el);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* curr = root;
        int pval = p->val, qval = q->val;
        while(1) {
            if(curr->val == qval || curr->val == pval) return curr;
            bool pleft = findme(curr->left, pval);
            bool qleft = findme(curr->left, qval);
            if(pleft && qleft) {
                curr = curr->left;
            } else if(pleft || qleft) {
                return curr;
            } else {
                curr = curr->right;
            }
        }
    }
};
