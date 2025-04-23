/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int n = 0, m = 0;
        ListNode* cura = headA;
        ListNode* curb = headB;
        while(cura != nullptr) n++, cura = cura->next;
        while(curb != nullptr) m++, curb = curb->next;
        int diff = abs(n-m);
        cura = headA;
        curb = headB;
        if(n > m) {
            while(diff--) cura = cura->next;
        } else {
            while(diff--) curb = curb->next;
        }
        while(cura != nullptr) {
            if(cura == curb) return cura;
            cura = cura->next;
            curb = curb->next;
        }
        return nullptr;
    }
};
