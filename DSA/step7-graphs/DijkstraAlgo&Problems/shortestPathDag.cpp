// User function Template for C++
class Solution {
  public:
  
    void dfs(vector<vector<pair<int,int>>> &adj, vector<bool> &visited, stack<int> &st, int i) {
        visited[i] = true;
        for(int j = 0; j<adj[i].size(); j++){
            if (!visited[adj[i][j].first]) {
                dfs(adj, visited, st, adj[i][j].first);
            }
        }
        st.push(i);
        
    }
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int,int>>> adj(V);
        
        for (auto i:edges){
            adj[i[0]].push_back({i[1], i[2]});
        }
        
        stack<int> topo;
        vector<bool> visited(V, false);
        
        for(int i = 0; i<V; i++){
            if (!visited[i]) {
                dfs(adj, visited, topo, i);
            }
        }
        
        vector<int> dist(V, INT_MAX);
        dist[0]=0;
        while(!topo.empty()){
            int node = topo.top();
            topo.pop();
            if (dist[node] == INT_MAX) continue;
            for (int i = 0; i<adj[node].size();i++){
                int node2 = adj[node][i].first;
                int cost = adj[node][i].second;
                dist[node2]=min(dist[node2], dist[node]+cost);
            }
        }
        for (int i = 0;i<V;i++){ if(dist[i]==INT_MAX) dist[i]=-1;}
        return dist;
        
    }
};
