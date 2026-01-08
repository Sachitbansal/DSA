class Solution {
  public:
  
    void dfs(vector<vector<int>> &adj, vector<bool> &visited, stack<int> &st, int i) {
        visited[i] = true;
        for(int j = 0; j<adj[i].size(); j++){
            if (!visited[adj[i][j]]) {
                dfs(adj, visited, st, adj[i][j]);
            }
        }
        st.push(i);
        
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        stack<int> st;
        vector<int> ans;
        
        vector<vector<int>> adj(V);
        for (int i = 0; i< edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        
        vector<bool> visited(V, false);
        
        for(int i = 0; i<V; i++){
            if (!visited[i]) {
                dfs(adj, visited, st, i);
            }
        }
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};