class Solution {
  public:
    void bfs(vector<vector<int>> &adj, vector<bool> &visited, queue<pair<int,int>> &q, bool &ans){
        
        while(!q.empty() && !ans) {
            pair<int, int> node = q.front();
            q.pop();
            int nod = node.first;
            int parent = node.second;
            for (int i = 0; i < adj[nod].size(); i++) {
                if (!visited[adj[nod][i]]) {
                    visited[adj[nod][i]] = true;
                    q.push({adj[nod][i], nod});
                } else if (adj[nod][i] != parent){
                    ans = true;
                    break;
                }
            }
        }
        
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        queue<pair<int,int>> q;
        vector<bool> visited(V, false);
        // visited[edges[0][0]] = true;
        bool ans = false;
        
        vector<vector<int>> adj(V);
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        for (int i = 0; i<visited.size(); i++){
            if (!visited[i]){
                q.push({i, -1});
                visited[i] = true;
                bfs(adj, visited, q, ans);
            }
        }
        
        
        
        
        return ans;
    }
}; 