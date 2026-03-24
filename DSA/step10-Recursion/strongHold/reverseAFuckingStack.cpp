class Solution {
  public:
  
    void insertAtBottom(stack<int> &st, int bottom) {
        if (st.empty()) {
            st.push(bottom);
            return;
        }
        
        int temp = st.top();
        st.pop();
        insertAtBottom(st, bottom);
        st.push(temp);
    }
  
    void reverseStack(stack<int> &st) {
        // code here
        if (st.empty()) return;
        int bottom = st.top();
        st.pop();
        
        reverseStack(st);
        
        insertAtBottom(st, bottom);
        
        
    }
};  