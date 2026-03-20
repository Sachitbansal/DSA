class Solution {
public:

    vector<int> nextGreater(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        vector<int> ans(n);

        ans[n-1] = n;
        st.push(n-1);
        for (int i = n-2; i >-1; i --) {
            while(!st.empty() && nums[i] >= nums[st.top()]){
                st.pop();
            }

            if (!st.empty()) ans[i] = st.top();
            else ans[i] = n;
            st.push(i);
        }
        return ans;
    }

    vector<int> prevGreater(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        vector<int> ans(n);

        ans[0] = -1;
        st.push(0);
        for (int i = 1; i < n; i++) {
            while(!st.empty() && nums[i] > nums[st.top()]){
                st.pop();
            }
            if (!st.empty()) ans[i] = st.top();
            else ans[i] = -1;
            st.push(i);
        }
        return ans;
    }

    vector<int> prevSmaller(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        vector<int> ans(n);

        ans[0] = -1;
        st.push(0);
        for (int i = 1; i < n; i++) {
            while(!st.empty() && nums[i] < nums[st.top()]){
                st.pop();
            }
            if (!st.empty()) ans[i] = st.top();
            else ans[i] = -1;
            st.push(i);
        }
        return ans;
    }

    vector<int> nextSmaller(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        vector<int> ans(n);

        ans[n-1] = n;
        st.push(n-1);
        for (int i = n-2; i > -1; i--) {
            while(!st.empty() && nums[i] <= nums[st.top()]){
                st.pop();
            }
            if (!st.empty()) ans[i] = st.top();
            else ans[i] = n;
            st.push(i);
        }
        return ans;
    }
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        // need to first solve sum of sub array minimums and then sub array maximums

        // ans will ne sub array maximums - sub array minimums
        vector<int> nextGreat = nextGreater(nums);
        vector<int> prevGreat = prevGreater(nums);
        vector<int> nextSmall = nextSmaller(nums);
        vector<int> prevSmall = prevSmaller(nums);

        // conditons for sub array maximums
        long long maximums = 0LL;
        long long minimums = 0LL;
        for (int i = 0; i < n; i++) {
            int nG = nextGreat[i];
            int pG = prevGreat[i];
            int nS = nextSmall[i];
            int pS = prevSmall[i];

            maximums += 1LL *(nG - i) * (i - pG) * nums[i];
            minimums += 1LL *(nS - i) * (i - pS) * nums[i];
        }

        return maximums - minimums;
    }
};