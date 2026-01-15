class Solution {
  public:
    void dfs(vector<vector<char>>& grid, vector<vector<bool>> &visited, int h, int w, int &height, int &width){
        if (0<=h && h<height && 0<=w && w<width && grid[h][w]=='L' && !visited[h][w]){
            
            visited[h][w] = true;
            
            dfs(grid, visited, h+1, w+1,height,width);   
            dfs(grid, visited, h-1, w-1,height,width);
            dfs(grid, visited, h+1, w-1,height,width);
            dfs(grid, visited, h-1, w+1,height,width);
            dfs(grid, visited, h+1, w,height,width);
            dfs(grid, visited, h, w+1,height,width);
            dfs(grid, visited, h-1, w,height,width);
            dfs(grid, visited, h, w-1,height,width);
        } else return;
    }
    int countIslands(vector<vector<char>>& grid) {
        // Code here
        int count = 0;
        int height = grid.size();
        int width = grid[0].size();
        vector<vector<bool>> visited(height, vector<bool>(width, false));
        
        for (int h = 0; h < height; h++) {
            for (int w = 0; w<width; w++){
                if (grid[h][w]=='L' && !visited[h][w]){
                    count++;
                    dfs(grid, visited, h, w, height, width);
                }
            }
        }
        return count;
        
    }
};