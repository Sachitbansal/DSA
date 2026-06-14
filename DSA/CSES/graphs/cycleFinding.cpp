#include<bits/stdc++.h>
using namespace std;

int main() {

    int nodes, edges;
    cin >> nodes >>edges;

    vector<vector<int>> adj;
    for (int i = 0; i < edges; i++) {
        int u, v, wt;
        cin >> u >> v>> wt;
        adj.push_back({u, v, wt});
    }
    vector<long long> dist(nodes+1, 0);
    vector<int> parents(nodes+1, -1);

    int x = -1;
    for (int i = 0; i < nodes; i++) {
        x = -1;
        for (int j = 0; j < edges; j++) {
            int u = adj[j][0];
            int v = adj[j][1];
            int wt = adj[j][2];
            if (dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
                parents[v] = u;
                x = v;
            } 
        }
    }
    if (x == -1) {
        cout << "NO";
        return 0;
    } else {
        cout << "YES" <<endl;
    }
    
    for (int i = 0; i < nodes; i++) {
        x = parents[x];
    }
   
    vector<int> path;
    int start = x;
    path.push_back(start);
    x = parents[x];

    while (x != start) {
        path.push_back(x);
        x = parents[x];
    }
    path.push_back(x);
    reverse(path.begin(), path.end());
    for (int i : path) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}