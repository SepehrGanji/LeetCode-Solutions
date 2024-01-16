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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
  ListNode* revHead = head;
  ListNode* prevOfRevHead = nullptr;
  for(int i = 1 ; i < left ; i++) {
    prevOfRevHead = revHead;
    revHead = revHead->next;
  }
  ListNode* prev = nullptr;
  ListNode* current = revHead;
  for(int i = left ; i <= right ; i++) {
    ListNode* nextTemp = current->next;
    current->next = prev;
    prev = current;
    current = nextTemp;
  }
  // We have to connect them (1)->(2)->(3)
  // (2)->(3)
  if(prevOfRevHead != nullptr)
    prevOfRevHead->next = prev;
  else
    head = prev;
  // (1)->(2)
  revHead->next = current;
  return head;
}
};
