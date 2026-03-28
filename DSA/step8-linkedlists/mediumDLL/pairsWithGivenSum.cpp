// User function Template for C++

/* Doubly linked list node class
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};
*/

class Solution {
  public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
        // code here
        vector<pair<int,int>> ans;
        if (!head) return ans;
        Node* pt1 = head;
        Node* pt2 = head;
        
        while(pt2->next) {
            pt2 = pt2->next;
        }
        
        while(pt1->data < pt2->data) {
            int sum = pt1->data + pt2->data;
            
            if (sum < target) {
                pt1 = pt1->next;
            } else if (sum == target) {
                ans.push_back({pt1->data, pt2->data});
                pt1 = pt1->next;
                pt2 = pt2->prev;
            } else {
                pt2 = pt2->prev;
            }
        }
        return ans;
    }
};