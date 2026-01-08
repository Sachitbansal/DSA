class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int &original, int &rows, int &cols, vector<int> &dx, vector<int> &dy, int& color){
        
        if (image[sr][sc] == original) {
            image[sr][sc] = color;
            for (int k = 0; k < 4; k++){
                if (0 <= sr + dx[k] && sr + dx[k] < rows && 0 <= sc + dy[k] && sr + dy[k] < cols) {
                    // if (image[sr + dx[k]][sc + dy[k]] == original) {
                        dfs(image, sr + dx[k], sc + dy[k], original, rows, cols, dx, dy, color);
                    // }
                }
            }
        }
        return;

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        // queue<pair<int,int>,int> q;
        int original = image[sr][sc];
        if (original == color) return image;
        // image[sr][sc] = color;
        // q.push({{sr, sc}, color});
        vector<int> dx = {0, 0, +1, -1};
        vector<int> dy = {1, -1, 0, 0};
        int rows = image.size();
        int cols = image[0].size();

        dfs(image, sr, sc, original, rows, cols, dx, dy, color);

        return image;
        

        

    }
};