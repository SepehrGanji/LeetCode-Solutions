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
    ListNode* rotateRight(ListNode* head, int k) {
        int n = 0;
        ListNode* tmp = head;
        ListNode* tail = nullptr;
        while(tmp != nullptr) {
            if(tmp->next == nullptr) tail = tmp;
            tmp = tmp->next;
            n++;
        }
        if(n == 0) return head;
        k %= n;
        if(k == 0) return head;
        tail->next = head;
        int ka = (n-k) - 1;
        tmp = head;
        while(ka--) {
            tmp = tmp->next;
        }
        ListNode* ans = tmp->next;
        tmp->next = nullptr;

        return ans;
    }
};
