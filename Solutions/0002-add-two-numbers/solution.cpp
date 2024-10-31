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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = (l1->val + l2->val) / 10;
        ListNode* ans = new ListNode((l1->val + l2->val) % 10);
        l1 = l1->next; l2 = l2->next;
        ListNode* curr = ans;
        while(1) {
            if(l1 == nullptr && l2 == nullptr && carry == 0) break;
            int val = carry;
            if(l1 != nullptr) {
                val += l1->val;
                l1 = l1->next;
            }
            if(l2 != nullptr) {
                val += l2->val;
                l2 = l2->next;
            }
            curr->next = new ListNode(val % 10);
            carry = val / 10;
            curr = curr->next;
        }
        
        return ans;
    }
};
