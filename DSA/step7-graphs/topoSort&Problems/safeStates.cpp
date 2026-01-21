class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<vector<int>> adj(graph.size());
        vector<int> inDegree(adj.size(), 0);

        for(int i = 0; i<graph.size(); i++){
            for (int j = 0; j<graph[i].size(); j++){
                adj[graph[i][j]].push_back(i);
                inDegree[i]++;
            }
        }
        queue<int> q;
        vector<int> ans;
        for (int i = 0; i<inDegree.size(); i++){
            if (!inDegree[i]) q.push(i);
        }

        while(!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for (int i = 0; i<adj[node].size();i++){
                inDegree[adj[node][i]]--;
                if (!inDegree[adj[node][i]]) q.push(adj[node][i]);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};