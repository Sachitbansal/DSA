// User function Template for C++
class DisjointSet {
    public:
    vector<int> parent, size;
    DisjointSet (int n) {
        parent.resize(n+1);
        size.resize(n+1, 1);
        
        for (int i = 0; i < n+1; i++) {
            parent[i] = i;
        }
            
    }
    
    int findUParent (int u) {
        if (u == parent[u]) return u;
        return parent[u] = findUParent(parent[u]);
    }
    
    void unionBySize(int u, int v) {
        int upu = findUParent(u);
        int upv = findUParent(v);
        
        if (upu == upv) return;
        if (size[upu] > size[upv]) {
            parent[upv] = upu;
            size[upu] += size[upv];
        } else {
            parent[upu] = upv;
            size[upv] += size[upu];
        }
    }
};

class Solution {
  public:
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        // code here
        
        vector<pair<int, pair<int,int>>> edge;
        for (int i = 0; i < edges.size(); i++) {
            int from = edges[i][0];
            int to = edges[i][1];
            int weight = edges[i][2];
            
            edge.push_back({weight, {to, from}});
        }
        
        sort(edge.begin(), edge.end());
        DisjointSet ds(V);
        int mstWt = 0;
        
        for (int i = 0; i < edge.size(); i++) {
            int weight = edge[i].first;
            int to = edge[i].second.first;
            int from = edge[i].second.second;
            
            if (ds.findUParent(to) != ds.findUParent(from)) {
                mstWt += weight;
                ds.unionBySize(from, to);
            }
        }
        
        return mstWt;
        
        
    }
};