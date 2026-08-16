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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int sz = 0;
        ListNode* curr = head;
        while (curr) {
            ++sz;
            curr = curr->next;
        }

        int next_rmv_node = sz-n;

        if (next_rmv_node == 0) {
            return head->next;
        } else {
            ListNode* another_curr = head;
            while (--next_rmv_node) {
                another_curr=another_curr->next;
            }
            another_curr->next = another_curr->next->next;
        }
        return head;
    }
};
