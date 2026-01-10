class Solution {
public:
    vector<int> dx = {0,0,1,-1};
    vector<int> dy = {1,-1,0,0};
    
    int height;
    int width;

    void dfs(vector<vector<int>>& grid, int &count, int h, int w, bool calc){

        grid[h][w] = 2;
        if (calc) count++;
        for (int k = 0; k<4; k++){
            if (0<= h+dy[k] && h+dy[k]<height && 0<=w+dx[k] && w+dx[k] <width && grid[h+dy[k]][w+dx[k]]==1) {
                dfs(grid, count, h+dy[k], w+dx[k], calc);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int count = 0;
        height = grid.size();
        width = grid[0].size();


        for( int i = 0; i<height; i++){
            if (grid[i][0] == 1){
                dfs(grid, count, i,0, false);
            }
            if (grid[i][width-1] == 1) {
                dfs(grid, count,i, width-1, false);
            }
        }

        for( int i = 0; i<width; i++){
            if (grid[0][i] == 1){
                dfs(grid, count,0,i, false);
            }
            if (grid[height-1][i] == 1) {
                dfs(grid, count,height-1, i, false);
            }
        }

        for (int h=1;h<height-1;h++){
            for(int w = 1;w<width-1;w++){
                if (grid[h][w]==1) {
                    dfs(grid, count, h, w, true);
                }
            }
        }
        return count;

    }
};