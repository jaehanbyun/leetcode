/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> ban;
        ban.reserve(nums.size());
        for (int x : nums) ban.insert(x);
        ListNode dummy = ListNode(0, head);
        ListNode* prev = &dummy;
        ListNode* cur = head;
        while (cur) {
            if (ban.count(cur->val)) {
                prev->next = cur->next;
                cur = cur->next;
            }
            else{
                prev = cur;
                cur = cur->next;
            }
        }
        return dummy.next;
    }
};