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
        ListNode* fastA = headA;
        ListNode* fastB = headB;
        
        while (fastA && fastB) {
            fastA = fastA->next;
            fastB = fastB->next;
        }
        while (fastA) {
            fastA = fastA->next;
            headA = headA->next;
        }
        while (fastB) {
            fastB = fastB->next;
            headB = headB->next;
        }
        while (headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
};
