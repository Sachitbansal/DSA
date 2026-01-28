class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
       // code here
        vector<vector<pair<int, int>>> adj(V);
        for (int i = 0; i < edges.size(); i++) {
            int from = edges[i][0];
            int to = edges[i][1];
            int weight = edges[i][2];
            
            adj[from].push_back({to, weight});
            adj[to].push_back({from, weight});
        }
        
        vector<bool> visited(V, false);
      
        priority_queue<
            pair<int,pair<int, int>>,
            vector<pair<int,pair<int, int>>>,
            greater<pair<int,pair<int, int>>>
        > pq;
        
        int sum = 0;
        
        vector<pair<int, int>> mst;
        // weight, to, from
        pq.push({0, {0, -1}});
        
        while(!pq.empty()){
            int weight = pq.top().first;
            int to = pq.top().second.first;
            int from = pq.top().second.second;
            pq.pop();
            if (!visited[to]) {
                mst.push_back({to, from});
                sum += weight;
                visited[to] = true;
            } else continue;
            
            for (int i = 0; i < adj[to].size(); i++) {
                if (!visited[adj[to][i].first]) {
                    pq.push({adj[to][i].second, {adj[to][i].first, from}});
                }
            }
        }
        return sum;
    }
};