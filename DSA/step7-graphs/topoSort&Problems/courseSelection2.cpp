class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (int i = 0; i< prerequisites.size(); i++) {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int> topo;
        vector<int> inDegree(numCourses, 0);
        for (int i = 0; i< numCourses; i++) {
            for (int j = 0; j<adj[i].size();j++){
                inDegree[adj[i][j]]++;
            }
        }

        queue<int> q;
        for (int i = 0; i<numCourses; i++){
            if (inDegree[i] == 0) q.push(i);
        }
        // vector<int> ans;

        while(!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(int i = 0; i<adj[node].size(); i++){
                inDegree[adj[node][i]]--;
                if (!inDegree[adj[node][i]]) q.push(adj[node][i]); 
            }
        }
        // while(!topo.empty()) {
        //     ans.push_back(topo.top());
        //     topo.pop();
        // }
        if (topo.size()<numCourses) return {};
        else return topo;
    }
};
