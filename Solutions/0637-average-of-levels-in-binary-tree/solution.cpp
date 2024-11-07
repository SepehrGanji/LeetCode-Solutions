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
void mmd(vector<vector<int>> &ans, TreeNode* el, int level) {
  if(el == nullptr) return;
  while(ans.size() < level + 1) {
    ans.push_back({});
  }
  ans.at(level).push_back(el->val);
  mmd(ans, el->left, level + 1);
  mmd(ans, el->right, level + 1);
}
    vector<double> averageOfLevels(TreeNode* root) {
        vector<vector<int>> ans = {};
        mmd(ans, root, 0);
        vector<double> final_ans = {};
        for(auto v: ans) {
            double su = 0;
            for(auto vv: v) su += vv;
            final_ans.push_back(su/v.size());
        }
        return final_ans;
    }
};
