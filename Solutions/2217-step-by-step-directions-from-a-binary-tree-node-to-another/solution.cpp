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
    string final_ans = "";

    bool find_path(TreeNode* root, int target, string& so_far) {
        if(root == nullptr) return false;
        if(root->val == target) {
            final_ans = so_far;
            return true;
        }
        so_far.push_back('L');
        if (find_path(root->left, target, so_far)) {
            return true;
        }
        so_far.pop_back();

        so_far.push_back('R');
        if (find_path(root->right, target, so_far)) {
            return true;
        }
        so_far.pop_back();

        return false;
        // return find_path(root->left, target, so_far+'L') || find_path(root->right, target, so_far+'R');
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        string A, B;
        find_path(root, startValue, A);
        find_path(root, destValue, B);
        // string B = final_ans;
        int i = 0;
        while(true) {
            if(i >= A.length() || i >= B.length()) break;
            if(A[i] != B[i]) break;
            i++;
        }
        string ans = "";
        for(int ai = i ; ai < A.length() ; ai++) ans += 'U';
        for(int ai = i ; ai < B.length() ; ai++) ans += B[ai];
        return ans;
    }
};
