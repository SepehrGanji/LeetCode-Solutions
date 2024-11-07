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
    int getMinimumDifference(TreeNode* root) {
        BSTIterator iter(root);
        int val = iter.next();
        int ans = INT_MAX;
        while(iter.hasNext()) {
            int val2 = iter.next();
            ans = min(ans, abs(val - val2));
            val = val2;
        }

        return ans;
    }
};
