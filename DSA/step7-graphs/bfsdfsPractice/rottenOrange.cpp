class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int time = 0;
        queue<pair<pair<int,int>,int>> q;
        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};
        int height = grid.size();
        int width = grid[0].size();

        for (int h = 0; h < height; h++) {
            for (int w = 0; w<width;w++) {
                if (grid[h][w] == 2) {
                    q.push({{h, w}, 0});
                }
            }
        }

        while(!q.empty()) {
            int size = q.size();

            for (int i = 0; i<size; i++) {
                pair<pair<int,int>, int> node = q.front();
                q.pop();
                int h = node.first.first;
                int w = node.first.second;
                int ti = node.second;
                for (int k = 0; k <4; k++) {
                    if (0 <= h + dy[k] && h + dy[k] < height && 0 <= w + dx[k] && w + dx[k] < width) {
                        if (grid[h + dy[k]][w + dx[k]] == 1){
                            grid[h + dy[k]][w + dx[k]] = 2;
                            q.push({{h + dy[k], w + dx[k]}, ti+1});

                        }
                    }
                    
                }
                time = max(time, ti);
            }
        }
        for (int h = 0; h < height; h++) {
            for (int w = 0; w<width;w++) {
                if (grid[h][w] == 1) {
                    return -1;
                }
            }
        }
        return time;
    }
};