class Solution {
    const int INF = INT_MAX;
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int m = rooms.size(), n = rooms[0].size();
        queue<pair<int,int>> q;

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (rooms[i][j] == 0) q.push({i, j});   

        int dr[4] = {-1, 1, 0, 0}, dc[4] = {0, 0, -1, 1};

        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();

            for (int d = 0; d < 4; ++d) {
                int nx = x + dr[d], ny = y + dc[d];

                if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                if (rooms[nx][ny] != INT_MAX) continue;  

                rooms[nx][ny] = rooms[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
};
