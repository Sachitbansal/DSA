#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);

    pair<int, int> A, B;

    for (int i = 0; i < n; i++) {
        cin >> grid[i];
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'A') A = {i, j};
            if (grid[i][j] == 'B') B = {i, j};
        }
    }

    vector<vector<bool>> vis(n, vector<bool>(m, false));
    vector<vector<pair<int, int>>> parent(
        n, vector<pair<int, int>>(m, {-1, -1})
    );

    queue<pair<int, int>> q;
    q.push(A);
    vis[A.first][A.second] = true;
    parent[A.first][A.second] = A;

    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        for (int k = 0; k < 4; k++) {
            int nr = r + dx[k];
            int nc = c + dy[k];

            if (nr < 0 || nr >= n || nc < 0 || nc >= m)
                continue;

            if (vis[nr][nc] || grid[nr][nc] == '#')
                continue;

            vis[nr][nc] = true;
            parent[nr][nc] = {r, c};
            q.push({nr, nc});
        }
    }

    if (!vis[B.first][B.second]) {
        cout << "NO\n";
        return 0;
    }

    vector<pair<int, int>> pathCells;

    pair<int, int> cur = B;

    while (cur != A) {
        pathCells.push_back(cur);
        cur = parent[cur.first][cur.second];
    }

    pathCells.push_back(A);
    reverse(pathCells.begin(), pathCells.end());

    string path;

    for (int i = 1; i < (int)pathCells.size(); i++) {
        int pr = pathCells[i - 1].first;
        int pc = pathCells[i - 1].second;

        int cr = pathCells[i].first;
        int cc = pathCells[i].second;

        if (cr == pr - 1) path += 'U';
        else if (cr == pr + 1) path += 'D';
        else if (cc == pc - 1) path += 'L';
        else if (cc == pc + 1) path += 'R';
    }

    cout << "YES\n";
    cout << path.length() << "\n";
    cout << path << "\n";

    return 0;
}
