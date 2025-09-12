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
class Solution {
public:
    // stack<int> rev(long long a) {
    //     stack<int> ans;
    //     while(a > 0) {
    //         ans.push(a % 10);
    //         a /= 10;
    //     }
    //     return ans;
    // }

    ListNode* plusOne(ListNode* head) {
        vector<int> vec;
        while(head != nullptr) {
            vec.push_back(head->val);
            head = head->next;
        }
        reverse(vec.begin(), vec.end());
        int carry = 1, i = 0;
        while(carry > 0 && i < vec.size()) { // can be for
            int d = vec[i];
            d += carry;
            carry = 0;
            if(d == 10) {
                d = 0;
                carry = 1;
            }
            vec[i] = d;
            i++;
        }
        if(carry == 1) vec.push_back(1);
        reverse(vec.begin(), vec.end());
        
        head = new ListNode(vec[0]);
        ListNode* cur = head;
        for(int i = 1 ; i < vec.size() ; i++) {
            ListNode* newno = new ListNode(vec[i]);
            cur->next = newno;
            cur = newno;
        }
        return head;
    }
};

