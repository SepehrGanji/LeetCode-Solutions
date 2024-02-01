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
    vector<int> arr;

void push(TreeNode* node) {
  if(node == nullptr) return;
  push(node->left);
  arr.push_back(node->val);
  push(node->right);
}

bool isValidBST(TreeNode* root) {
  push(root);
  for(int i = 1 ; i < arr.size() ; i++) {
    if(arr[i-1] >= arr[i]) return false;
  }
  return true;
}
};
