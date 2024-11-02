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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 0; ListNode* tmp = head;
        while(tmp != nullptr) {
            tmp = tmp->next;
            size++;
        }
        n = size-n+1;

        if(n == 1) {
            head = head->next;
            return head;
        }

        tmp = head;
        while(1) {
            n--;
            if(n == 1) {
                tmp->next = tmp->next->next; 
                break;
            }
            tmp = tmp->next;
        }

        return head;
    }
};
