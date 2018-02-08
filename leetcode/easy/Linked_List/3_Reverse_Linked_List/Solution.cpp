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
    ListNode* reverseList(ListNode* head) {
        if (head==NULL || head->next == NULL)
            return head;
        
        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* nxt;
        while (curr->next != NULL) {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        curr->next = prev;
        head->next = NULL;
        
        return curr;
    }
};
