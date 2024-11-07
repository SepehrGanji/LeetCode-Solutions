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
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        BSTIterator iter(root);
        int val = iter.next();
        while(iter.hasNext()) {
            int val2 = iter.next();
            if(val >= val2) return false;
            val = val2;
        }
        return true;
    }
};
