class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;

        for (int i = 0; i < heights.size(); i++) {

            while (!st.empty() && heights[st.top()] > heights[i]) {
                int currHeight = heights[st.top()];
                int right = i;
                st.pop();
                int left = st.empty() ? -1 : st.top();
                maxArea = max(maxArea, currHeight * (right - left - 1));
            }
            st.push(i);
        }

        while(!st.empty()) {
            int currHeight = heights[st.top()];
            int right = heights.size();
            st.pop();
            int left = st.empty() ? -1 : st.top();

            maxArea = max(maxArea, currHeight * (right - left - 1));
        }

        return maxArea;
    }
};