/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    Node* reverse (Node* head) {
        
        Node* current = head;
        Node* prev = NULL;
        Node* next = NULL;
        while (current) {
            next = current->next;
            
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }
    Node* addOne(Node* head) {
        // Your Code here
        int carry = 1;
        
        Node* revHead = reverse(head);
        Node* current = revHead;
        while(current) {
            if (current->data != 9) {
                current->data = current->data + 1;
                return reverse(revHead);
            } else {
                current->data = 0;
                if (!current->next) {
                    Node* temp = new Node(1);
                    current->next = temp;
                    // revHead = temp;
                    return reverse(revHead);
                }
                current=current->next;
            }
            
        }
        return NULL;
        
        
        // return head of list after adding one
    }
};