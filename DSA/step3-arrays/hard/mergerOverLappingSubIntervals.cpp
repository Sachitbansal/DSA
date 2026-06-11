class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        ans.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++) {
            int lower = intervals[i][0];
            int upper = intervals[i][1];
            
            int lastL = ans.back()[0];
            int lastU = ans.back()[1];

            if (lastU >= lower) {
                // there is interserction we can merge
                ans.back()[1] = max(ans.back()[1], upper);
            } else {
                // no intersection - add directoly to ans;
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};;
