class Solution {
  public:
    void act(int nod, vector<bool> &visited, vector<int> &ans, vector<vector<int>>& adj) {
        int size = adj[nod].size();
        for (int i = 0; i < size; i++) {
            if (!visited[adj[nod][i]]){
                visited[adj[nod][i]] = true;
                ans.push_back(adj[nod][i]);
                act(adj[nod][i], visited, ans, adj);
            } 
        } return;
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        vector<bool> visited(adj.size(), false);
        vector<int> ans;
        ans.push_back(0);
        visited[0] = true;
        act(0, visited, ans, adj);
        return ans;
        
    }
};
