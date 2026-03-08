#include <bits/stdc++.h>
using namespace std;

// Node class represents a node in the linked list
class Node {
public:
    int data;     // Data value
    Node* next;   // Pointer to next node

    // Constructor with data and next
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    // Constructor with only data
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

Node* insertNode (int val, Node* head, int pos) {
    Node* temp = new Node(val);

    if (pos ==0) {
        temp->next = head;
        return temp;
    }
    Node* current = head;
    for (int i = 0; i < pos - 1 && current != NULL; i++) {
        current = current->next;
    }

    if (current == NULL) return head; // invalid position

    temp->next = current->next;
    current->next = temp;
    return head;

}

void print(Node* head) {
    Node* current = head;
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
}

int main() {
    // Create an array
    vector<int> arr = {2, 5, 8, 7};

    // Create first node
    Node* y = new Node(arr[0]);

    // Print memory location of node
    cout << y << '\n';

    // Print data stored in node
    cout << y->data << '\n';

    for (int i : arr) {
        print(insertNode(i, y, 1));
        cout << endl;
    }

    return 0;
}
