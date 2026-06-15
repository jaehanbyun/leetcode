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
    ListNode* deleteMiddle(ListNode* head) {
        if (head->next == nullptr) {
            return nullptr;
        }
        ListNode* curr = head;
        int len = 0;

        while (curr != nullptr) {
            len++;
            curr = curr->next;
        }

        int middle = len / 2;
        curr = head;
        ListNode* prev;
        while (middle--) {
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;

        return head;
    }
};