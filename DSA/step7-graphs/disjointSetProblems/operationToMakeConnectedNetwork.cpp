class DisjointSet{
    public:
    vector<int> parent, size;
    DisjointSet(int n) {
        parent.resize(n+1);
        size.resize(n+1, 1);

        for (int i = 0; i < n+1; i++) {
            parent[i] = i;
        }
    }

    int findUParent(int n) {
        if (n == parent[n]) return n;
        return parent[n] = findUParent(parent[n]);
    }

    void unionBySize(int u,int v) {
        int upu = findUParent(u);
        int upv = findUParent(v);

        if (upu == upv) return;
        if (size[upu] > size[upv]) {
            size[upu] += size[upv];
            parent[upv] = upu;
        } else {
            size[upv] += size[upu];
            parent[upu] = upv;
        }
    
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int extra = 0;
        for (int i = 0; i< connections.size(); i++) {
            if (ds.findUParent(connections[i][0]) == ds.findUParent(connections[i][1])) {
                extra++;
            } else ds.unionBySize(connections[i][0], connections[i][1]);
        }

        int count = 0;
        for (int i = 1; i < n; i++) {
            if (ds.findUParent(0) != ds.findUParent(i)) {
                count ++;
                ds.unionBySize(0, i);
            }
        }

        if (extra >= count ) return count;
        return -1;
    }
};