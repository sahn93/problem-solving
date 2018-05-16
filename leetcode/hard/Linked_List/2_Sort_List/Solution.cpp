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
    ListNode* sortList(ListNode* head) {
        // Merge sort.
        if (head == NULL || head->next == NULL) {
            return head;
        }
        
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* frontlast = head;
        while (fast != NULL && fast->next != NULL) {
            frontlast = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        frontlast->next = NULL;
        
        return merge(sortList(head), sortList(slow));
    }
    
    ListNode* merge(ListNode* l, ListNode* r) {
        ListNode* head = new ListNode(0);
        ListNode* curr = head;
        while (l && r) {
            if (l->val < r->val) {
                curr->next = l;
                l = l->next;
            } else {
                curr->next = r;
                r = r->next;
            }
            curr = curr->next;
        }
        if (l) curr->next = l;
        else curr->next = r;
            
        return head->next;
    }
};
