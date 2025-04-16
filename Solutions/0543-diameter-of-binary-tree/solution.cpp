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
    // (ans, longest)
    typedef pair<int, int> tup;

    tup solve(TreeNode* root) {
        if(root == nullptr) {
            return tup(0, 0);
        }
        tup l = solve(root->left);
        tup r = solve(root->right);
        int ans_go_me = r.second + l.second;
        int how_long = max(r.second, l.second) + 1;
        return tup(max(ans_go_me, max(r.first, l.first)), how_long);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        return solve(root).first;
    }
};
