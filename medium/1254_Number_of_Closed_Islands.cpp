class Solution {
    int m, n;
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

public:
    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0 && bfsIsClosed(grid, i, j)) res++;
            }
        }
        return res;
    }

private:
    bool bfsIsClosed(vector<vector<int>>& grid, int r, int c) {
        bool closed = true;
        queue<pair<int, int>> q;
        q.push({r, c});
        grid[r][c] = 1;                      

        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();

            if (isBorder(x, y)) closed = false;

            for (int k = 0; k < 4; ++k) {
                int nx = x + dr[k], ny = y + dc[k];
                if (!inRange(nx, ny) || grid[nx][ny] != 0) continue;
                grid[nx][ny] = 1;            
                q.push({nx, ny});
            }
        }
        return closed;
    }

    bool isBorder(int r, int c) {
        return r == 0 || r == m - 1 || c == 0 || c == n - 1;
    }

    bool inRange(int r, int c) {
        return 0 <= r && r < m && 0 <= c && c < n;
    }
};