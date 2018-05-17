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
        unordered_map<RandomListNode*, RandomListNode*> oton;
        RandomListNode *curr = head;
        while (curr) {
            RandomListNode *copy = new RandomListNode(curr->label);
            oton[curr] = copy;
            curr = curr->next;
        }
        
        curr = head;
        while (curr) {
            oton[curr]->next = oton[curr->next];
            oton[curr]->random = oton[curr->random];
            curr = curr->next;
        }
        
        return oton[head];
    }
};
