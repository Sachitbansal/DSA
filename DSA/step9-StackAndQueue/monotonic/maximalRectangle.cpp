class Solution {
public:

    int maxAreaReturn (vector<int> heights) {
        int n = heights.size();
        stack<int> st;
        
        int maxArea = 0;

        for (int i = 0; i < n; i ++) {
            
            while(!st.empty() && heights[st.top()] > heights[i]) {
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
            int right = n;
            st.pop();
            int left = st.empty() ? -1 : st.top();
            maxArea = max(maxArea, currHeight * (right - left - 1));
        }

        return maxArea;

    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int ans = 0;
        vector<int> heights(matrix[0].size(), 0);
        for(int i = 0; i < matrix.size(); i ++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == '1') {
                    heights[j]++;
                } else heights[j] = 0;
            }
            ans = max(ans, maxAreaReturn(heights));
        }
        return ans;
    }
};