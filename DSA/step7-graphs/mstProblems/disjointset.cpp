#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> rank, parent;
public: 
    DisjointSet(int n) {
        rank.resize(n+1, 0);
        parent.resize(n+1);
        for (int i = 0; i < n+1; i++) {
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
        } else if (rank[upv] < rank[upu]) {
            parent[upv] = upu;
        } else {
            parent[upv] = upu;
            rank[upu]++;
        }
    }
}


int main() {


    return 0;
}