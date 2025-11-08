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
    vector<TreeNode*> arr;
    
    void trav(TreeNode* root) {
        if(root == nullptr) return;
        trav(root->left);
        arr.push_back(root);
        trav(root->right);
    }
    
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        trav(root);
        for(int i = 0 ; i < arr.size()-1 ; i++) {
            if(arr[i] == p) return arr[i+1];
        }
        return nullptr;
    }
};
