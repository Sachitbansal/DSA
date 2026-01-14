class Solution {
public:
    bool dfs(vector<vector<int>>& graph, int node, int col, vector<int> &color) {
        color[node] = col;
        for(int i = 0; i < graph[node].size(); i++) {
            if (color[graph[node][i]] == -1){
                if (!dfs(graph, graph[node][i], col==0?1:0, color)) return false;
            } else if (color[graph[node][i]] == col){
                return false;
            } 
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(), -1);
        bool ans;
        for (int i =0;i<graph.size(); i++){
            if (color[i]== -1){
                ans = dfs(graph, i, 0, color); 
                if (!ans) return false;
            }
        }
      
        return true;
        
    }
};