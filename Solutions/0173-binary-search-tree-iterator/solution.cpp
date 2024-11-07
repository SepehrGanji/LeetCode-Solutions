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
class BSTIterator {
public:
    stack<TreeNode*> vv;
    BSTIterator(TreeNode* root) {
        push(root);
    }
    
    int next() {
        TreeNode* el = vv.top(); vv.pop();
        push(el->right);
        return el->val;
    }

    void push(TreeNode* el) {
        if(el == nullptr) return;
        vv.push(el);
        push(el->left);
    }
    
    bool hasNext() {
        return vv.empty() == false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
