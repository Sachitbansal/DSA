class Solution {
public:

    bool validCo(vector<vector<char>> &grid, int currR, int currY) {
        int r = grid.size();
        int c = grid[0].size();

        if (0 <= currR && currR < r && 0 <= currY && currY < c) return true;
        return false; 
    }

    bool f(vector<vector<char>> &grid, int currR, int currC, int orrR, int orrC, vector<vector<bool>> &visited, int prevR, int prevC) {

        
        visited[currR][currC] = true;
        bool ans = false;
        int dx[] = {0, 0, -1, 1};
        int dy[] = {1, -1, 0, 0};

        for (int i = 0; i< 4; i++) {
            int r = currR + dx[i];
            int c = currC + dy[i];
            if (validCo(grid, r, c)) {
                // if (visited[r][c] && (r != prevR || c != prevC) && r == orrR && c == orrC) return true;
                if (visited[r][c] && (r != prevR || c != prevC) &&  grid[r][c] == grid[currR][currC]) return true;

                if (!visited[r][c] && grid[r][c] == grid[currR][currC]) {
                    ans = ans || f(grid, r, c, orrR, orrC, visited, currR, currC);
                }
            }
        }
        return ans;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));

        // visited[0][0] = true;

        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                if (!visited[r][c]) {
                    if (f(grid, r, c, r,c, visited, -1, -1)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
