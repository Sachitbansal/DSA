class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<int> inDegree(V, 0);
        
        vector<vector<int>> adj(V);
        
        for (int i = 0; i<edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        
        for (int i = 0; i<adj.size(); i++){
            for (int j =0; j<adj[i].size(); j++) {
                inDegree[adj[i][j]]++;
            }
        }
        
        queue<int> q;
        for (int i=0; i<V; i++){
            if (inDegree[i] == 0){
                q.push(i);
            }
        }
        vector<int> topo;
        
        while(!q.empty()) {
            int nod = q.front();
            topo.push_back(nod);
            q.pop();
            
            for (int i = 0; i<adj[nod].size(); i++) {
                inDegree[adj[nod][i]]--;
                if (inDegree[adj[nod][i]] == 0) {
                    q.push(adj[nod][i]);
                }
            }
        }
        return topo;
    }
};