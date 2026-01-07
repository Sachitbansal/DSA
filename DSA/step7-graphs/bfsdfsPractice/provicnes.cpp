class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, int nod, vector<bool> &visited) {
        int size = isConnected[nod].size();
        for (int i = 0; i < size; i++) {
            if (isConnected[nod][i] && i != nod && !visited[i]) {
                visited[i] = true;
                dfs(isConnected, i, visited);
            }
        }
        return;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int count = 0;
        if (isConnected.size()==1) return 1;
        vector<bool> visited(isConnected.size()-1, false);
        for (int j = 0; j < isConnected.size(); j++) {
            if (!visited[j]){
                count++;
                dfs(isConnected, j, visited);
            }
        }
        return count;
    }
}; 