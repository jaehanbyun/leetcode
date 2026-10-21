class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        queue<pair<int, int>> q;
        vector<vector<int>> tMap(m, vector<int>(n, -1));
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                    tMap[i][j] = 0;
                }
            }
        }
        
        auto inRange = [&](int r, int c) {
            return 0 <= r && r < m && 0 <= c && c < n;
        };

        auto bfs = [&]() -> void {            
            while (!q.empty()) {
                auto [x, y] = q.front(); q.pop();

                for (int i=0; i<4; ++i) {
                    int nx = x + dr[i];
                    int ny = y + dc[i];

                    if (!inRange(nx, ny) || grid[nx][ny] != 1 || tMap[nx][ny] != -1) continue;

                    tMap[nx][ny] = tMap[x][y] + 1;
                    q.push({nx, ny});
                }    
            }
        };

        bfs();

        int res = 0;
        for (int i=0; i<m; ++i)
            for (int j=0; j<n; ++j) {
                if (grid[i][j] == 1 && tMap[i][j] == -1) return -1;  
                res = max(res, tMap[i][j]);
            }
        return res;
    }
};