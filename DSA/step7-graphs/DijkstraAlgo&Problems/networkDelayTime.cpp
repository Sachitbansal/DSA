class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);

        for (int i = 0; i < times.size(); i++){
            int from = times[i][0];
            int to = times[i][1];
            int time = times[i][2];
            adj[from].push_back({to, time});
        }

        vector<int> timeTaken(n+1, INT_MAX);
        timeTaken[0] = 0;
        timeTaken[k] = 0;
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        int ans = 0;
        // time, from
        pq.push({0, k});
        while(!pq.empty()){
            int time = pq.top().first;
            int from = pq.top().second;
            pq.pop();
            // ans = max(ans, time);

            if (time > timeTaken[from]) continue;

            for (int i = 0; i < adj[from].size(); i++){
                int to = adj[from][i].first;
                int weight = adj[from][i].second;

                if (time + weight < timeTaken[to]) {
                    timeTaken[to] = time + weight;
                    pq.push({time +weight, to});
                }
            }
        }
        for (int i:timeTaken) {
            if (i == INT_MAX) return -1;
            ans = max(ans, i);
        }
        return ans;
    }
};