/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        // Space complexity: O(1)
        RandomListNode *curr = head;
        
        // Copy and concat the duplication next to the original one.
        while (curr) {
            auto next = curr->next;
            auto copy = new RandomListNode(curr->label);
            curr->next = copy;
            copy->next = next;
            
            curr = next;
        }
        
        // Copy randoms.
        curr = head;
        while (curr) {
            auto copy = curr->next;
            if (curr->random) {
                copy->random = curr->random->next;
            }
            curr = copy->next;
        }
        
        // Extract the copied list and restore the original list.
        curr = head;
        auto chead = new RandomListNode(0);
        auto ccurr = chead;
        while (curr) {
            auto next = curr->next->next;
            
            auto copy = curr->next;
            ccurr->next = copy;
            ccurr = copy;
            
            curr->next = next;
            
            curr = next;
        }
        
        return chead->next;
    }
};
