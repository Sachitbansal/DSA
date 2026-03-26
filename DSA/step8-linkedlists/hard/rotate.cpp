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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return NULL;
        int n = 0;
        ListNode* temp = head;

        while(temp->next){
            n++;
            temp = temp->next;
        }
        n++;

        if (k%n == 0) return head;
        k %= n;
        // temp = temp->next;
        temp->next = head;
        temp = head;
        int toMove = n-k-1;
        ListNode* ans = NULL;
        while(toMove) {
            toMove--;
            temp = temp->next;
        }
        ans = temp->next;
        temp->next = NULL;
        return ans;

    }
};