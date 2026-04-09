class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<pair<int,int>> obs;
        for (auto &o : obstacles) obs.insert({o[0], o[1]});

        int x = 0, y = 0;
        int facing = 0; // 0=N,1=E,2=S,3=W
        int dx[4] = {0,1,0,-1};
        int dy[4] = {1,0,-1,0};

        int maxDist = 0;

        for (int cmd : commands) {
            if (cmd == -1) facing = (facing + 1) % 4;
            else if (cmd == -2) facing = (facing + 3) % 4;
            else {
                for (int i = 0; i < cmd; i++) {
                    int nx = x + dx[facing];
                    int ny = y + dy[facing];

                    if (obs.count({nx, ny})) break;

                    x = nx;
                    y = ny;
                    maxDist = max(maxDist, x*x + y*y);
                }
            }
        }
        return maxDist;
    }
};