/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool isMatch(ListNode* curr, TreeNode* root) {
        if(curr == nullptr) return true;
        if(root == nullptr) return false;
        if(curr->val != root->val) return false;
        return isMatch(curr->next, root->left) || isMatch(curr->next, root->right);
    }

    bool proc(ListNode* head, TreeNode* root) {
        if(root == nullptr) return false;
        bool ans = isMatch(head, root);
        if(ans) return true;
        return proc(head, root->left) || proc(head, root->right);
    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        return proc(head, root);
    }
};
