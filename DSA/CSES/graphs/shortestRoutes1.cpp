#include<bits/stdc++.h>
using namespace std;

int main() {

    int nodes, edges;
    cin >> nodes >> edges;

    vector<vector<pair<int, int>>> adj(nodes+1);
    
    for (int i = 0; i < edges; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back({v, c});
    }

    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;

    pq.push({0, 1});
    vector<long long> dist(nodes+1, 1e18);
    dist[1] = 0;
    while(!pq.empty()) {
        pair<long long, long long> ele = pq.top();
        pq.pop();
        long long d = ele.first;
        long long node = ele.second;
        if (d > dist[node]) continue;
        for (long long i = 0; i < adj[node].size(); i++) {
            long long n = adj[node][i].first;
            long long wt = adj[node][i].second;
            
            if (dist[n] > wt + d) {
                dist[n] = wt + d;
                pq.push({dist[n], n});
            }
        }
    }

    for (long long i = 1; i < nodes+1; i++) {
        cout << dist[i] << " ";
    }
    cout << endl;

    return 0;
}