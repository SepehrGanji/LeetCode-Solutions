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
    ListNode* rev(ListNode* li) {
        vector<int> vc;
        while(li != nullptr) {
            vc.push_back(li->val);
            li = li->next;
        }
        reverse(vc.begin(), vc.end());
        ListNode* ans = new ListNode(vc[0]);
        ListNode* tmp = ans;
        for(int i = 1 ; i < vc.size() ; i++) {
            ListNode* mmd = new ListNode(vc[i]);
            tmp->next = mmd;
            tmp = mmd;
        }
        return ans;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l11 = rev(l1);
        ListNode* l22 = rev(l2);
        ListNode* head = new ListNode();
        ListNode* ans = head;
        
        int carry = 0;
        while(l11 != nullptr || l22 != nullptr) {
            int tmp = carry;
            if(l11 != nullptr) {
                tmp += l11->val;
                l11 = l11->next;
            }
            if(l22 != nullptr) {
                tmp += l22->val;
                l22 = l22->next;
            }
            carry = tmp/10;
            tmp = tmp % 10;
            ans->next = new ListNode(tmp);
            ans = ans->next;
        }
        if(carry != 0) {
            ans->next = new ListNode(carry);
        }
        head = head->next;
        return rev(head);
    }
};
