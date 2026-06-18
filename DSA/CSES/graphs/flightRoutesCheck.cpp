#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<bool>&visited, vector<vector<int>> &adj) {
    visited[node] = true;

    for (int v : adj[node]) {
        if (!visited[v]) {
            dfs(v, visited, adj);
        }
    }
}

int main() {

    int n,e;
    cin >> n >>e;

    vector<vector<int>> adj(n+1);
    vector<vector<int>> revadj(n+1);
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        revadj[v].push_back(u);
    }

    int compo = n;
    vector<bool> visited(n+1, false);
    int falsee = -1;
    dfs(1, visited, adj);
    for (int i = 1; i < n+1; i++) {
        if (!visited[i]) {
            falsee = i;
            break;
        }
    }
    if (falsee != -1) {
        cout << "NO" <<endl;
        cout << 1 << " " <<falsee<<endl;
        return 0;
    }
    for (int i = 1; i <= n; i++) visited[i] = false;
    falsee = -1;
    dfs(1, visited, revadj);
    for (int i = 1; i < n+1; i++) {
        if (!visited[i]) {
            falsee = i;
            break;
        }
    }
    if (falsee != -1) {
        cout << "NO" <<endl;
        cout << falsee << " " <<1<<endl;
        return 0;
    }

    cout << "YES"<<endl;
    return 0;
}