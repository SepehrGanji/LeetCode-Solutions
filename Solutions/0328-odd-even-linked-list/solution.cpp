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
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr || head->next == nullptr || head->next->next == nullptr) return head;
        ListNode* h1 = head;
        ListNode* h2 = head->next;
        ListNode* cur1 = h1;
        ListNode* cur2 = h2;
        head = head->next->next;
        bool yay = true;
        while(head != nullptr) {
            if(yay){
                cur1->next = head;
                cur1 = head;
            } else {
                cur2->next = head;
                cur2 = head;
            }
            yay = !yay;
            head = head->next;
        }
        cur1->next= nullptr;
        cur2->next= nullptr;
        // stitch
        cur1 = h1;
        while(cur1->next != nullptr) cur1 = cur1->next;
        cur1->next = h2;
        return h1;
    }
};
