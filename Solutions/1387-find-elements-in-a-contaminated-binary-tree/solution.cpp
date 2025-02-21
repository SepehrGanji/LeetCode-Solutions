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
class FindElements {
public:
    unordered_map<int, bool> mp;
    void recover(TreeNode* root, int val) {
        if(root == nullptr) return;
        root->val = val;
        mp[val] = true;
        recover(root->left, val*2 + 1);
        recover(root->right, val*2 + 2);
    }

    FindElements(TreeNode* root) {
        recover(root, 0);
    }
    
    bool find(int target) {
        if(mp.find(target) == mp.end()) return false;
        return true;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
