/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {number[]} nums
 * @param {ListNode} head
 * @return {ListNode}
 */
var modifiedList = function(nums, head) {
    const st = new Set(nums);
    const fake_head = new ListNode(0);
    let current = fake_head;
    while(head != null) {
        if(st.has(head.val)) {
            head = head.next;
        } else {
            current.next = new ListNode(head.val);
            head = head.next;
            current = current.next;
        }
    }
    return fake_head.next;
};

