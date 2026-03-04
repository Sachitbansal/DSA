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

        ListNode* dummy = new ListNode(-1);
        ListNode* current = dummy;
        ListNode* it1 = l1;
        ListNode* it2 = l2;
        int carry = 0;

        while(it1 && it2) {
            int val1 = it1->val;
            int val2 = it2->val;

            it1 = it1->next;
            it2 = it2->next;
            int val = val1 + val2 + carry;

            if (val < 10) {
                ListNode* node = new ListNode(val);
                current->next = node;
                current = current->next;
                carry = 0;
            } else {
                ListNode* node = new ListNode(val % 10);
                current->next = node;
                carry = (val) / 10;
                current = current->next;
            }
        }

        while (it1) {
            int val1 = it1->val;
            it1 = it1->next;
            int val = val1 + carry;

            if (val < 10) {
                ListNode* node = new ListNode(val);
                current->next = node;
                current = current->next;
                carry = 0;
            } else {
                ListNode* node = new ListNode(val % 10);
                current->next = node;
                carry = (val) / 10;
                current = current->next;
            }
        }
        while (it2) {
            int val2 = it2->val;
            it2 = it2->next;
            int val = val2 + carry;

            if (val < 10) {
                ListNode* node = new ListNode(val);
                current->next = node;
                current = current->next;
                carry = 0;
            } else {
                ListNode* node = new ListNode(val % 10);
                current->next = node;
                carry = (val) / 10;
                current = current->next;
            }
        }

        if (carry != 0) {
            ListNode* node = new ListNode(carry);
            current->next = node;
        }

        return dummy->next;

    }
};