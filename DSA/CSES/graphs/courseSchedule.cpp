#include<bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<vector<int>> &adj, vector<bool> &visited, stack<int> &st, vector<bool> &recVis) {
    
    visited[node] = true;
    recVis[node] = true;
    for (int i = 0; i < adj[node].size(); i++) {
        if (!visited[adj[node][i]]) {
            // visited[adj[node][i]] = true;
            if (dfs(adj[node][i], adj, visited, st, recVis)) return true;
        } else if (recVis[adj[node][i]]) return true;
    }
    st.push(node);
    recVis[node] = false;
    return false;
}

int main() {

    int nodes ,edges;
    cin >> nodes >> edges;

    vector<vector<int>> adj(nodes+1);
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    stack<int> st;
    vector<bool> recVis(nodes+1, false);
    vector<bool> visited(nodes+1, false);
    bool found = false;
    for (int i = 1; i < nodes+1; i++) {
        if (!visited[i]) {
            found = dfs(i, adj, visited, st, recVis);
            if (found) break;
        }
    }
    if (found) {
        cout << "IMPOSSIBLE";
        return 0;
    }
    vector<int> ans;
    while (!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    for (int i : ans) {
        cout << i << " ";
    }

    return 0;
}