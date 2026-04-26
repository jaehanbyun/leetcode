class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        function<bool(int,int,int,int,char)> dfs = [&](int x, int y, int px, int py, char ch) {
            visited[x][y] = true;

            static int dx[4] = {1, -1, 0, 0};
            static int dy[4] = {0, 0, 1, -1};

            for (int i=0; i<4; ++i) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                if (nx == px && ny == py) continue;
                if (grid[nx][ny] != ch) continue;
                if (visited[nx][ny]) return true;
                if (dfs(nx, ny, x, y, ch)) return true;
            }
            return false;
        };

        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (!visited[i][j]) {
                    if (dfs(i, j, -1, -1, grid[i][j])) return true;
                }
            }
        }

        return false;
    }
};