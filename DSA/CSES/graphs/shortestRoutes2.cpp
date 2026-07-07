#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, m, q;
    cin >> n >> m >> q;

    const long long INF = 1e18;

    vector<vector<long long>> dist(n + 1, vector<long long>(n + 1, INF));

    // Distance from a node to itself is 0
    for (int i = 1; i <= n; i++) {
        dist[i][i] = 0;
    }

    // Read edges
    for (int i = 0; i < m; i++) {
        int u, v;
        long long wt;
        cin >> u >> v >> wt;

        // Multiple edges can exist
        dist[u][v] = min(dist[u][v], wt);
        dist[v][u] = min(dist[v][u], wt);
    }

    // Floyd-Warshall
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            if (dist[i][k] == INF) continue;

            for (int j = 1; j <= n; j++) {
                if (dist[k][j] == INF) continue;

                dist[i][j] = min(dist[i][j],
                                 dist[i][k] + dist[k][j]);
            }
        }
    }

    // Answer queries
    while (q--) {
        int u, v;
        cin >> u >> v;

        if (dist[u][v] == INF)
            cout << -1 << '\n';
        else
            cout << dist[u][v] << '\n';
    }

    return 0;
}