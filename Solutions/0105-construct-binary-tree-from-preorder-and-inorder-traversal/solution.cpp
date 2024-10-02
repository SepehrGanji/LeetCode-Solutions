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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        if(n == 0) return nullptr;
        TreeNode* ans = new TreeNode(preorder[0]);
        if(n == 1) return ans;
        vector<int> left_pre, left_in;
        int i = 1, j = 0;
        while(inorder[j] != preorder[0]) {
            left_pre.push_back(preorder[i++]);
            left_in.push_back(inorder[j++]);
        }
        ans->left = buildTree(left_pre, left_in);
        vector<int> right_pre, right_in;
        while(i < n) right_pre.push_back(preorder[i]), right_in.push_back(inorder[i]), i++;
        ans->right = buildTree(right_pre, right_in);
        return ans;
    }
};
