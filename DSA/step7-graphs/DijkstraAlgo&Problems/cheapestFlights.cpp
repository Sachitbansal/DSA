class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);

        for (int i = 0; i < flights.size(); i++) {
            int from = flights[i][0];
            int to = flights[i][1];
            int price = flights[i][2];

            adj[from].push_back({to, price});
        }

        queue<pair<int, pair<int,int>>> pq;

        // first one for stops, second for price and third for from;
        pq.push({0, {0, src}});
        // int ans = INT_MAX;
        vector<int> dist(n, INT_MAX);

        while(!pq.empty()) {
            pair<int, pair<int,int>> it = pq.front();
            int price = it.first;
            int stop = it.second.first;
            int from = it.second.second;
            pq.pop();

            if (stop > k) break;

            for (int i = 0; i<adj[from].size(); i++) {
                int to = adj[from][i].first;
                int cost = adj[from][i].second;
                if (price + cost < dist[to]) {
                    dist[to] = price+cost;
                    pq.push({cost+price, {stop+1, to}});                
                }
            }
        }

        return dist[dst]== INT_MAX ? -1 : dist[dst];
    }
};