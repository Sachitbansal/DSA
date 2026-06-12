class DisjointSet {
    vector<int> parent, rank;

public:
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (node == parent[node]) return node;

        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {

        int upu = findUPar(u);
        int upv = findUPar(v);

        if (upu == upv) return;

        if (rank[upu] < rank[upv]) {
            parent[upu] = upv;
        }
        else if (rank[upu] > rank[upv]) {
            parent[upv] = upu;
        }
        else {
            parent[upv] = upu;
            rank[upu]++;
        }
    }
};

bool valid(int r, int c, int n, int m) {

    return (r >= 0 && r < n && c >= 0 && c < m);
}

vector<int> numOfIslandsII(int n, int m, vector<vector<int>> &q) {

    DisjointSet ds(n * m);

    vector<vector<int>> grid(n, vector<int>(m, 0));

    vector<int> ans;

    int islands = 0;

    // 8 directions
    vector<pair<int,int>> dir = {
		{-1,0},
		{1,0},
		{0,-1},
		{0,1}
	};

    for (int i = 0; i < q.size(); i++) {

        int r = q[i][0];
        int c = q[i][1];

        // already land
        if (grid[r][c] == 1) {
            ans.push_back(islands);
            continue;
        }

        grid[r][c] = 1;

        islands++;

        int node = r * m + c;

        for (auto d : dir) {

            int nr = r + d.first;
            int nc = c + d.second;

            if (valid(nr, nc, n, m) && grid[nr][nc] == 1) {

                int adjNode = nr * m + nc;

                if (ds.findUPar(node) != ds.findUPar(adjNode)) {

                    islands--;

                    ds.unionByRank(node, adjNode);
                }
            }
        }

        ans.push_back(islands);
    }

    return ans;
}