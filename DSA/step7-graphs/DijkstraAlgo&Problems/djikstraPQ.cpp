class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<pair<int,int>>> adj(V);
        for ( int i = 0; i<edges.size(); i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        
        vector<int> dist(V, INT_MAX);
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;
        
        pq.push({0, src});
        dist[src] = 0;
        
        while(!pq.empty()) {
            int distTillNode = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            if (distTillNode > dist[node]) continue;
            
            for (int i = 0; i <adj[node].size(); i++){
                int weight = adj[node][i].second;
                int nextNode = adj[node][i].first;
                
                if (weight + distTillNode < dist[nextNode]) {
                    dist[nextNode] = weight + distTillNode;
                    pq.push({weight + distTillNode ,nextNode});
                }
            }
        }
        return dist;
    }
};
