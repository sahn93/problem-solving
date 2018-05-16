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
        vector<int> nums;
        for (ListNode* l: lists) {
            while(l) {
                nums.push_back(l->val);
                l = l->next;
            }
        }
        sort(nums.begin(), nums.end());
        ListNode* curr = NULL;
        ListNode* res = NULL;
        for (int i=0; i<nums.size(); i++) {
            if (!curr) {
                curr = new ListNode(nums[i]);
                res = curr;
            } else {
                curr->next = new ListNode(nums[i]);
                curr = curr->next;
            }
        }
        return res;
    }
};
