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
    ListNode* reverse(ListNode* head) {
        ListNode* current = head;
        ListNode* prev = NULL; 
        ListNode* next = NULL;
        while(current) {
            next = current->next;

            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        int count = 0;
        while(slow) {
            count ++;
            slow = slow->next;
        }

        slow = head;
        if (count % 2 == 0) {
            // even elements means fast will be outside lenth
            while(fast) {
                slow = slow->next;
                fast = fast->next->next;
            }

            ListNode* revhead = reverse(slow);
            slow = head;
            ListNode* temp = revhead;
            count /=2;
            while(count) {
                count --;
                if (slow->val == temp->val) {
                    slow = slow->next;
                    temp=temp->next;
                } else return false;
            }
            return true;
        } else {
            // odd elements means fast will be last of length
            while(fast->next) {
                slow = slow->next;
                fast = fast->next->next;
            }

            ListNode* revhead = reverse(slow->next);
            slow = head;
            ListNode* temp = revhead;
            count /=2;
            while(count) {
                count --;
                if (slow->val == temp->val) {
                    slow = slow->next;
                    temp=temp->next;
                } else return false;
            }
            return true;
        }
    }
};