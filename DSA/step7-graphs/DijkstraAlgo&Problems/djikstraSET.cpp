class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<pair<int,int>>> adj(V);
        for ( int i = 0; i<edges.size(); i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        
        set<pair<int, int>> st;
        vector<int> dist(V, INT_MAX);
        
        st.insert({0, src});
        dist[src] = 0;
        
        while(!st.empty()) {
            auto it = *(st.begin());
            int distTillNode = it.first;
            int node = it.second;
            st.erase(it);
            
            if (distTillNode > dist[node]) continue;
            
            for (int i = 0; i <adj[node].size(); i++){
                int weight = adj[node][i].second;
                int nextNode = adj[node][i].first;
                
                if (weight + distTillNode < dist[nextNode]) {
                    
                    if (dist[nextNode] != INT_MAX) st.erase({dist[nextNode], nextNode});
                    
                    dist[nextNode] = weight + distTillNode;
                    st.insert({weight + distTillNode ,nextNode});
                }
            }
        }
        return dist;
    }
};