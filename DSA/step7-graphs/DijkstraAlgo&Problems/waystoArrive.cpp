class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int mod = 1e9 + 7;

        vector<vector<pair<int,int>>> adj(n);
        for (auto &r : roads) {
            adj[r[0]].push_back({r[1], r[2]});
            adj[r[1]].push_back({r[0], r[2]});
        }

        vector<long long> dist(n, LLONG_MAX);
        vector<long long> ways(n, 0);

        dist[0] = 0;
        ways[0] = 1;

        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > pq;

        pq.push({0, 0});

        while (!pq.empty()) {
            auto [time, node] = pq.top();
            pq.pop();

            if (time > dist[node]) continue;

            for (auto &[to, cost] : adj[node]) {
                long long newTime = time + cost;

                if (newTime < dist[to]) {
                    dist[to] = newTime;
                    ways[to] = ways[node];
                    pq.push({newTime, to});
                } 
                else if (newTime == dist[to]) {
                    ways[to] = (ways[to] + ways[node]) % mod;
                }
            }
        }

        return ways[n-1] % mod;
    }
};

