class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {

        stack<int> st;
        int n = nums.size();
        vector<int> ans(n);
        st.push(nums[n-1]);

        for(int i = n-2; i >-1 ; i--){
            while (!st.empty() && nums[i] > st.top()) {
                st.pop();
            }
            st.push(nums[i]);
        }

        for (int i = n-1; i > -1; i--) {
            while (!st.empty() && nums[i] >= st.top()) {
                st.pop();
            }
            if (!st.empty()) ans[i] = st.top();
            else ans[i] = -1;
            st.push(nums[i]);
        }
        return ans;
        
    }
};
