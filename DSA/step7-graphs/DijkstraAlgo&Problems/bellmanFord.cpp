// User function Template for C++

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        // vector<vector<pair<int ,int>>> adj(V);
        // for (int i = 0; i<edges.size(); i++){
        //     int from = edges[i][0];
        //     int to = edges[i][1];
        //     int weight = edges[i][2];
            
        //     adj[from].push_back({to, weight});
        // }
        
        vector<int> dist(V, 1e8);
        dist[src] = 0;
        
        for (int i = 0; i < V; i++){
            
            for (int j = 0; j < edges.size(); j++) {
                int from = edges[j][0];
                int to = edges[j][1];
                int weight = edges[j][2];
                
                if (dist[from] == 1e8) continue;
                
                if (dist[from] + weight < dist[to]) {
                    dist[to] = dist[from] +weight;
                }
            }
        }
        
        for (int j = 0; j < edges.size(); j++) {
                int from = edges[j][0];
                int to = edges[j][1];
                int weight = edges[j][2];
                
                if (dist[from] == 1e8) continue;
                
                if (dist[from] + weight < dist[to]) {
                    return {-1};
                }
        }
        
        
        return dist;
    }
};
