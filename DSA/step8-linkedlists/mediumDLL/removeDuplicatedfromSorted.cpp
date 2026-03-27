/*
struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }

};
*/

class Solution {
  public:

    Node *removeDuplicates(struct Node *head) {
        if (!head) return head;
        // Your code here
        int val = head->data;
        Node* current = head;
        Node* lastKnown = head;
        
        while(current) {
            int newVal = current->data;
            if (newVal != val) {
                lastKnown->next = current;
                current->prev = lastKnown;
                lastKnown = current;
                val = current->data;
                
            }
            current = current->next;
        }
        lastKnown->next = NULL;
        return head;
    }
};