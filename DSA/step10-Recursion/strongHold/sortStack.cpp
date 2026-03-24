class Solution {
  public:
  
    void insertAtRightPosition(stack<int> &st, int temp) {
        if (st.empty()){
            st.push(temp);
            return;
        }
        
        int val = st.top();
        if (val > temp) {
            st.pop();
            insertAtRightPosition(st, temp);
            st.push(val);
        } else {
            st.push(temp);              
        }
    }
  
    void sortStack(stack<int> &st) {
        // code here
        if (st.empty()) return;
        
        int temp = st.top();
        st.pop();
        
        sortStack(st);
        
        insertAtRightPosition(st, temp);
        
    }
};
