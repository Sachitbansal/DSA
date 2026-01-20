class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0]!=0)return -1;
        int height = grid.size();
        vector<vector<int>> dist(height, vector<int>(height, INT_MAX));
        dist[0][0]=1;
        queue<pair<pair<int,int>,int>> q;
        q.push({{0,0}, 1});

        const vector<int> dx = {0, 0, 1,-1, 1, -1, 1, -1};
        const vector<int> dy = {1,-1, 0, 0, 1, -1, -1, 1};

        while(!q.empty()) {
            int h = q.front().first.first;
            int w = q.front().first.second;
            int travelled = q.front().second;
            q.pop();

            if (h==height -1 && w==height-1) return travelled;

            for (int k = 0; k<8;k++){
                int nextH = h + dy[k];
                int nextW = w + dx[k];

                if (0<=nextH && 0<=nextW && nextH<height && nextW<height && grid[nextH][nextW]==0) {
                    if (travelled + 1 < dist[nextH][nextW]) {
                        // if (nextH==height-1 && nextW==height-1) return travelled+1;
                        dist[nextH][nextW] = travelled + 1;
                        q.push({{nextH, nextW}, travelled+1});
                    }
                }
            }
        }
        return -1;
    }
};