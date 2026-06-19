#include <bits/stdc++.h>
using namespace std;
int colSize;
int rowSize;
void bfs(int i, int j, vector<vector<bool>> &visited, vector<vector<char>> &mp){
    visited[i][j] = true;
    
    queue<pair<int, int>> q;
    q.push({i, j});
    
    while (!q.empty()) {
        pair<int, int> ele = q.front();
        int c = ele.first;
        int r = ele.second;
        
        // visited[c][r] = true;
        q.pop();
        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};
        
        for (int k = 0; k < 4; k++) {
            int nc = c + dx[k];
            int nr = r + dy[k];
            
            if (0 <= nc && nc < colSize && 0<= nr && nr < rowSize) {
                if (mp[nc][nr] == '.' && !visited[nc][nr]) {
                    q.push({nc, nr});
                    visited[nc][nr] = true;
                }
            }
        }
    }
}

int main() {
	
	cin >> colSize >> rowSize;
	
	vector<vector<char>> mp(colSize, vector<char>(rowSize));
	for (int i = 0; i < colSize; i++) {
	    for (int j = 0; j < rowSize; j++) {
	        cin >> mp[i][j];
	    }
	}
	
	int components = 0;
    vector<vector<bool>> visited(colSize, vector<bool>(rowSize, false));
	for (int i = 0; i < colSize; i++) {
	    for (int j = 0; j < rowSize; j++) {
	        if (mp[i][j] == '.' && !visited[i][j]) {
	            components++;
	            bfs(i, j, visited, mp);
	        }
	    }
	}
	cout << components<< endl;
	return 0;

}
