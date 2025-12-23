#include <bits/stdc++.h>
using namespace std;


struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    Node (int val){
        data = val;
        left = right = NULL;
    }
};

vector<int> IterativePostOrder2(Node* root) {

        vector<int> ans;
        if (root==NULL) return ans;
        stack<Node*> st1;
        stack<Node*> st2;
        st1.push(root);

        while (!st1.empty()){
            root = st1.top();
            st2.push(root);
            st1.pop();
            if (root->left!=NULL){st1.push(root->left);}
            if (root->right!=NULL){st1.push(root->right);}
        }
        while(!st2.empty()){
            ans.push_back(st2.top()->data);
            st2.pop();
        }
        return ans;
    
}
vector<int> IterativePostOrder1(Node* root) {

        vector<int> ans;
        if (root==NULL) return ans;
        stack<Node*> st;
        
        Node* curr = root;
        Node* temp = NULL;
        while(curr!= NULL || !st.empty()) {
            if (curr != NULL) {
                st.push(curr);
                curr = curr->left;
            } else {
                temp = st.top()->right;
                if (temp==NULL){
                    temp = st.top();
                    st.pop();
                    ans.push_back(temp->data);
                    while(!st.empty() && temp == st.top()->right) {
                        temp = st.top(); st.pop();
                        ans.push_back(temp->data);
                    }
                } else {
                    curr = temp;
                }
            }
        }

        return ans;
    
}



int main() {
    
    struct Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(5);
    root->left->right->left = new Node(8);
    root->left->left = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->right->left = new Node(9);
    root->right->right->right = new Node(10);

    vector<int> ans = IterativePostOrder2(root);

    cout << "final traversal ";
    // cout << arr.size();
    for (auto i: ans){
            cout << i;
    }

   
    return 0;
}
