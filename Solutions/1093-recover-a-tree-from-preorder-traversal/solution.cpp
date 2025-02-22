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
    TreeNode* recoverFromPreorder(string traversal) {
        TreeNode* root = nullptr;
        stack<TreeNode*> st;
        for(int i = 0 ; i < traversal.length() ; ) {
            int depth = 0;
            while(i < traversal.length() && traversal[i] == '-') depth++, i++;
            int val = 0;
            while(i < traversal.length() && traversal[i] != '-') {
                val *= 10;
                val += (traversal[i] - '0');
                i++;
            }
            TreeNode* node = new TreeNode(val);
            if(depth == 0) root = node;
            else {
                while(st.size() > depth) st.pop();
                if(st.top()->left == nullptr) st.top()->left = node;
                else st.top()->right = node;
            }
            st.push(node);
        }
        return root;
    }
};
