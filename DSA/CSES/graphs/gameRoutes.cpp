#include<bits/stdc++.h>
using namespace std;

void dfs(stack<int> &st, vector<vector<int>> &adj, vector<bool> &visited, int node) {
    visited[node] = true;

    for (int v : adj[node]) {
        if (!visited[v]) {
            dfs(st, adj, visited, v);
        }
    }
    st.push(node);
}

int main() {

    int n, e;
    cin>> n >> e;
    
    vector<vector<int>> adj(n+1);
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    stack<int> st;
    vector<bool> visited(n+1, false);
    
    dfs(st, adj, visited, 1);
    
    vector<int> topo;
    while(!st.empty()) {
        topo.push_back(st.top());
        st.pop();
    }

    // topo order ready
    int mod = 1e9 + 7;
    vector<long long> dist(n+1, 0);
    dist[1] = 1LL;
    for (int u : topo) {
        for (int v : adj[u]) {
            dist[v] = (dist[u] + dist[v]) % mod;
        }
    }
    
    cout << dist[n] % mod;

    return 0;
}