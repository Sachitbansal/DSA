class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        
        int n = arr.size();
        vector<int> prevSmaller(n);
        vector<int> nextSmaller(n);
        stack<int> st;

        st.push(n-1);
        nextSmaller[n-1] = n;
        
        for (int i = n-2; i > -1; i--) {
            while(!st.empty() && arr[i] <= arr[st.top()]) {
                st.pop();
            }
            if (!st.empty()) {
                nextSmaller[i] = st.top();
            } else nextSmaller[i] = n;
            st.push(i);
        }

        while(!st.empty()) st.pop();

        prevSmaller[0] = -1;
        st.push(0);
        for (int i = 1; i < n; i++) {
            while(!st.empty() && arr[i] < arr[st.top()]) {
                st.pop();
            }
            if (!st.empty()) prevSmaller[i] = st.top();
            else prevSmaller[i] = -1;
            st.push(i);
        }

        long long ans = 0;
        int mod = int(1e9 + 7);

        for (int i = 0; i < n; i ++) {
            int prev = prevSmaller[i];
            int next = nextSmaller[i];

            long long val = 1LL * (i - prev) * arr[i] * (next - i);
            ans = (ans + val) % mod; 
        }
        return ans;
        
    }
};