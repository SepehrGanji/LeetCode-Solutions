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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr && list2 == nullptr) return nullptr;
        ListNode* ans = new ListNode();
        ListNode* ptr = ans;
        while(list1 != nullptr && list2 != nullptr) {
            int l1 = list1->val, l2 = list2->val;
            if(l1 < l2) {
                ListNode* newnode = new ListNode(l1);
                list1 = list1->next;
                ptr->next = newnode;
                ptr = newnode;
            } else {
                ListNode* newnode = new ListNode(l2);
                list2 = list2->next;
                ptr->next = newnode;
                ptr = newnode;
            }
        }
        while(list1 != nullptr) {
                ListNode* newnode = new ListNode(list1->val);
                list1 = list1->next;
                ptr->next = newnode;
                ptr = newnode;
        }
        while(list2 != nullptr) {
            ListNode* newnode = new ListNode(list2->val);
            list2 = list2->next;
            ptr->next = newnode;
            ptr = newnode;
        }
        return ans->next;
    }
};
