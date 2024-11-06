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
    bool find(TreeNode* root, int val) {
        if(root == nullptr) return false;
        if(root->val == val) return true;
        return find(root->left, val) || find(root->right, val);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* curr = root;
        int qv = q->val;
        int pv = p->val;
        while(1) {
            if(curr->val == qv || curr->val == pv) return curr;
            bool qvleft = find(curr->left, qv);
            bool qvright = find(curr->right, qv);
            bool pvleft = find(curr->left, pv);
            bool pvright = find(curr->right, pv);
            if(qvleft && pvleft) {
                curr = curr->left;
            } else if(qvright && pvright) {
                curr = curr->right;
            } else {
                return curr;
            }
        }
    }
};
