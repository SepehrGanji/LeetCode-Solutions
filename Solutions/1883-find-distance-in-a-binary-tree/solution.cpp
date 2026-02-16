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
    bool find(TreeNode* root, int val) {
        if(root == nullptr) return false;
        if(root->val == val) return true;
        return find(root->left, val) || find(root->right, val);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, int pv, int qv) {
        TreeNode* curr = root;
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

    int find_level(TreeNode* root, int key, int level) {
        if(root == nullptr) return 0;
        if(root->val == key) return level;
        return find_level(root->left, key, level+1) + find_level(root->right, key, level+1);
    }

    int findDistance(TreeNode* root, int p, int q) {
        int LA =  find_level(root, p, 0);
        int LB =  find_level(root, q, 0);
        int LCA = lowestCommonAncestor(root, p, q)->val;
        int LC = find_level(root, LCA, 0);
        return LA + LB - (2 * LC);
    }
};
