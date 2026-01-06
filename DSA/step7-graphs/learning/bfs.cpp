class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        vector<bool> visited(adj.size(), false);
        queue<int> q;
        q.push(0);
        visited[0] = true;
        vector<int> ans;
        ans.push_back(0);
        
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            int size = adj[node].size();
            for (int i = 0; i < size; i++) {
                if (!visited[adj[node][i]]) {
                    visited[adj[node][i]] = true;
                    ans.push_back(adj[node][i]);
                    q.push(adj[node][i]);
                }
            }
        }
        return ans;
    }
};