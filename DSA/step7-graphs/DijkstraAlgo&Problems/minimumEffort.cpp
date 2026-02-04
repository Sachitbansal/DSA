class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        priority_queue<
            pair<int,pair<int, int>>,
            vector<pair<int,pair<int, int>>>,
            greater<pair<int,pair<int, int>>>
        > pq;
        int height = heights.size();
        int width = heights[0].size();
        pq.push({0, {0, 0}});
        vector<vector<int>> dist(height, vector<int>(width, INT_MAX));
        dist[0][0] = 0;
        
        const vector<int> dx = {0,0,1,-1};
        const vector<int> dy = {1,-1,0,0};
        
        while(!pq.empty()){
            int effort = pq.top().first;
            int h = pq.top().second.first;
            int w = pq.top().second.second;
            pq.pop();
            if (h==height-1 && w==width-1) return effort;
            if (effort > dist[h][w]) continue;

            for (int i = 0; i<4;i++){
                int nextH = h+dy[i];
                int nextW = w+dx[i];

                if (0<=nextH && 0<=nextW && nextH<height && nextW<width){
                    int diff = max(abs(heights[nextH][nextW] - heights[h][w]), effort);
                    if (diff < dist[nextH][nextW]) {
                        dist[nextH][nextW] = diff;
                        pq.push({diff, {nextH, nextW}});
                    }
                }
            }
        }
        return -1;
    }
};