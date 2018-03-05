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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* tail = head;
        int carry = 0;
        while (l1 || l2 || carry) {
            int sum = (l1?l1->val:0) + (l2?l2->val:0) + carry;
            tail->next = new ListNode(sum%10);
            tail = tail->next;
            carry = sum/10;
            l1 = l1?l1->next:nullptr;
            l2 = l2?l2->next:nullptr;
        }
        return head->next;
    }
};
