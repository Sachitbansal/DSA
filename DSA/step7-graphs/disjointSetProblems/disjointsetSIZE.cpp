#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> parent, size;

    DisjointSet(int n) {
        parent.resize(n+1);
        size.resize(n+1, 1);
        for (int i = 0; i < n+1; i++) {
            parent[i] = i;
        }
    }

    int findUParent(int node) {
        if (node == parent[node]) return node;
        return parent[node] = findUParent(parent[node]);
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

int main() {
    return 0;
}