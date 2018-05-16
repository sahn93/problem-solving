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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        int interval = 1;
        while (interval < k) {
            for (int i=0; i < k-interval; i+=(interval*2)) {
                lists[i] = merge2Lists(lists[i], lists[i+interval]);
            }
            interval*=2;
        }
        return (k > 0) ? lists[0] : NULL;
    }
    
    ListNode* merge2Lists(ListNode* l, ListNode* r) {
        if (!l) return r;
        else if (!r) return l;
        else {
            ListNode* head = new ListNode(0);
            ListNode* curr = head;
            while (l && r)  {
                if (l->val < r->val) {
                    curr->next = l;
                    l = l->next;
                } else {
                    curr->next = r;
                    r = r->next;
                }
                curr = curr->next;
            }
            if (l) {
                curr->next = l;
            } else {
                curr->next = r;
            }
            return head->next;
        }
    }
};
