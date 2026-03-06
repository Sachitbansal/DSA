#include <bits/stdc++.h>
using namespace std;

// Class representing a node in Doubly Linked List
class Node {
public:
    // Stores data of the node
    int data;

    // Pointer to the next node
    Node* next;

    // Pointer to the previous node
    Node* prev;

    // Constructor when data, next and prev are provided
    Node(int data1, Node* next1, Node* prev1) {
        data = data1;
        next = next1;
        prev = prev1;
    }

    // Constructor when only data is provided
    Node(int data1) {
        data = data1;
        next = nullptr;
        prev = nullptr;
    }
};


Node* insertNode(Node* head, int val, int pos) {
    Node* temp = new Node(val);

    // insert at head
    if (pos == 0) {
        temp->next = head;
        if (head) head->prev = temp;
        return temp;
    }

    Node* curr = head;
    int idx = 0;

    // move to (pos - 1)th node
    while (curr != nullptr && idx < pos - 1) {
        curr = curr->next;
        idx++;
    }

    // insert at end or middle
    if (curr == nullptr) return head;

    temp->next = curr->next;
    temp->prev = curr;

    if (curr->next) {
        curr->next->prev = temp;
    }
    curr->next = temp;

    return head;
}


void print(Node* head) {
    Node* current = head;
    int cont = 0;
    while (current) {
        cont++;
        cout << current->data << " ";
        current = current->next;
        if (cont == 6) break;
    }
}

Node* reverse(Node* head) {
    if (head == nullptr || head->next == nullptr) return head;
    
    Node* current = head;
 

    while (current) {
        Node * temp = current->next;
        current->next = current->prev;
        current->prev = temp;

        head = current;
        current = temp;
        
    }
    return head;
}

int main() {
    vector<int> arr = {2, 5, 8, 7};
    Node* head = nullptr;

    for (int i = 0; i < arr.size(); i++) {
        head = insertNode(head, arr[i], i);
    }

    cout << "Original DLL: ";
    print(head);

    head = reverse(head);   // save the new head!

    cout << "Reversed DLL: ";
    print(head);

    return 0;
}