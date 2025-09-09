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
    typedef pair<double, pair<int, int>> mmd;
    
    mmd solve(TreeNode* root) {
        if(root == nullptr) return {0, {0, 0}};
        auto l_ans = solve(root->left);
        auto r_ans = solve(root->right);
        int local_sum = (root->val + l_ans.second.first + r_ans.second.first);
        double local_cnt = 1 + l_ans.second.second + r_ans.second.second;
        double local = local_sum / local_cnt;
        return {max(local, max(l_ans.first, r_ans.first)), {local_sum, local_cnt}};
    }

    double maximumAverageSubtree(TreeNode* root) {
        return solve(root).first;
    }
};

