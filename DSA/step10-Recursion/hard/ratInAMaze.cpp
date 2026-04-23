class Solution {
  public:
  
    bool outOfBounds(int row, int col, int n) {
        if (row == n || col == n || row == -1 || col ==-1) return true;
        return false;
    }
  
    void f(vector<vector<int>> &maze, string &curr,  vector<string> &ans, int row, int col) {
        int n = maze.size();
        if (outOfBounds(row, col, n)) return;
        if (maze[row][col] == 0 || maze[row][col] == -1) return;
        if (row == n-1 && col == n-1) {
            ans.push_back(curr);
            return;
        }
        maze[row][col] = -1;
        
        // keeping only down and right
        curr.push_back('D');
        f(maze, curr, ans, row+1, col);
        curr.pop_back();
        
        curr.push_back('L');
        f(maze, curr, ans, row, col-1);
        curr.pop_back();
        
        curr.push_back('R');
        f(maze, curr, ans, row, col+1);
        curr.pop_back();
        
        // up and left
        curr.push_back('U');
        f(maze, curr, ans, row-1, col);
        curr.pop_back();
        
        maze[row][col] = 1;
        
    }
  
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        vector<string> ans;
        string curr = "";
        // vector<vector<bool>> tracking(maze.size(), vector<bool>(maze.size(), false));
        f(maze, curr, ans, 0, 0);
        return ans;
        
    }
};