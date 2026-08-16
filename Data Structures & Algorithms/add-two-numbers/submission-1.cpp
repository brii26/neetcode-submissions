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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        bool plus_one = false;
        ListNode* new_node = nullptr;
        ListNode* curr;
        while (l1 && l2) {
            int value = (plus_one) ? (1 + l1->val + l2->val) : (l1->val + l2->val);
            int node_value = value%10;
            plus_one = (value/10 == 1);
            if (new_node == nullptr) {
                new_node = new ListNode(node_value, nullptr);
                curr = new_node;
            } else {
                ListNode* another_new_node = new ListNode(node_value, nullptr);
                curr->next = another_new_node;
                curr = curr->next;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        ListNode* l3 = (l1 == nullptr) ? l2 : l1;
        ListNode* curr3 = l3;
        while (curr3) {
            int value = (plus_one) ? (curr3->val+1) : (curr3->val);
            int node_value = value%10;
            plus_one = (value/10 == 1);
            ListNode* another_one = new ListNode(node_value, nullptr);
            curr->next = another_one;
            curr = curr->next;
            curr3 = curr3->next;
        }

        if (plus_one) {
            ListNode* leading_one = new ListNode(1,nullptr);
            curr->next = leading_one;
        }
        return new_node;
    }
};
