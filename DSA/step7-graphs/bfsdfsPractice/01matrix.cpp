class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int height = mat.size();
        int width = mat[0].size();

        // vector<vector<bool>> visited(height, vector<bool>(width, false));
        vector<vector<int>> dist(height, vector<int>(width, -1));
        queue<pair<pair<int,int>, int>> q;

        for (int h = 0; h<height; h++) {
            for (int w = 0; w < width; w++) {
                if (mat[h][w] == 0) {
                    q.push({{h,w}, 0});
                    dist[h][w] = 0;
                }
            }
        }
        vector<int> dx = {0,0,1,-1};
        vector<int> dy = {1,-1,0,0};

        while(!q.empty()){
            int h = q.front().first.first;
            int w = q.front().first.second;
            int steps = q.front().second;
            q.pop();

            for (int k = 0; k<4; k++) {
                if (0<= h+dy[k] && h+dy[k]<height && 0<=w+dx[k] && w+dx[k] <width && dist[h+dy[k]][w+dx[k]]==-1) {
                    // visited[h+dy[k]][w+dx[k]] = true;
                    q.push({{h+dy[k], w+dx[k]}, steps+1});
                    dist[h+dy[k]][w+dx[k]] = steps+1;
                }
            }
        }
        return dist;
    }
};