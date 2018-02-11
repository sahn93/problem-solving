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
    bool isPalindrome(ListNode* head) {
        if (head==NULL) {
            return true;
        }
        // reverse front half, compare the first half and the last half
        int cnt=0;
        ListNode* lhead = NULL;
        ListNode* rhead = head;
        ListNode* last = head;
        ListNode* tmp;
        while (last->next != NULL) {
            cnt++;
            last = last->next->next;
            
            // reverse left half
            tmp = rhead->next;
            rhead->next = lhead;
            lhead = rhead;
            rhead = tmp;
            
            if (last == NULL) {
                break;
            }
        }
        if (last != NULL)
            rhead = rhead->next;
        
        while (rhead && lhead) {
            if (rhead->val != lhead->val)
                return false;
            rhead = rhead->next;
            lhead = lhead->next;
        }
        return true;
    }
};
