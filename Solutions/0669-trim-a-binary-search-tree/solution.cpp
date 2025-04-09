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
    int lo;
    int hi;
    
    bool inRange(int val) {
        if(val < lo) return false;
        if(val > hi) return false;
        return true;
    }
    
    TreeNode* solve(TreeNode* root) {
        if(root == nullptr) return root;
        if(inRange(root->val)) {
            root->left = solve(root->left);
            root->right = solve(root->right);
            return root;
        }
        // root not in range!!!!
        auto sr = solve(root->right);
        auto sl = solve(root->left);
        if(sr != nullptr) return sr;
        if(sl != nullptr) return sl;
        // if(root->left != nullptr && inRange(root->left->val)) return solve(root->left);
        return nullptr;
    }
    
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        this->lo = low;
        this->hi = high;
        return solve(root);
    }
};
