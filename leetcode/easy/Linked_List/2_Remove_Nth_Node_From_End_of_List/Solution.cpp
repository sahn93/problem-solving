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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr = head;
        ListNode* beforeremove = head;
        while(n-->0) {
            curr = curr->next;
        }
        
        // remove head 
        if (curr == NULL) {
            return head->next;
        }
        
        curr = curr->next;
        
        while(curr != NULL) {
            beforeremove = beforeremove->next;
            curr = curr->next; 
        }
        
        // remove last
        if (beforeremove->next->next == NULL)
            beforeremove->next = NULL;
        else {
            *beforeremove->next = *beforeremove->next->next;
        }
        
        return head;
    }
};
