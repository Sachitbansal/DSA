class Solution {
  public:

    void dfs(vector<vector<int>> &adj, vector<bool> &visited, bool &ans, int last, int nod) {
        
        for (int i = 0; i<adj[nod].size();i++) {
            if (!visited[adj[nod][i]]){
                visited[adj[nod][i]] = true;
                dfs(adj, visited, ans, nod, adj[nod][i]);
            } else if (adj[nod][i] != last) {
                ans = true;
                return;
            }
        }
    }
    
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here

        vector<bool> visited(V, false);

        bool ans = false;
        
        vector<vector<int>> adj(V);
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        for (int i = 0; i<visited.size(); i++){
            if (!visited[i]){
                visited[i] = true;
                if (!ans) dfs(adj, visited, ans, -1, i);
            }
        }
        
        return ans;
    }
}; 