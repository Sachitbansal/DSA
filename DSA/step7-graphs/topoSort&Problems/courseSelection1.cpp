class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (int i = 0; i< prerequisites.size(); i++) {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        int topo=0;
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

        while(!q.empty()) {
            int node = q.front();
            q.pop();
            topo++;
            for(int i = 0; i<adj[node].size(); i++){
                inDegree[adj[node][i]]--;
                if (!inDegree[adj[node][i]]) q.push(adj[node][i]); 
            }
        }
        if (topo<numCourses) return false;
        else return true;
    }
};