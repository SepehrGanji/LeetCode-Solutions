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
    void recurse(vector<int> &ans, TreeNode* el, int level){
  if(el == nullptr) return;
  if(ans.size() < level + 1) {
    ans.push_back(el->val);
  }
  recurse(ans, el->right, level + 1);
  recurse(ans, el->left, level + 1);
}

vector<int> rightSideView(TreeNode* root) {
  vector<int> ans = {};
  recurse(ans, root, 0);
  return ans;
}
};
