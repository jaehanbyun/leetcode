class Solution {
    int m, n;
    int dr[4] = {0, 0, -1, 1};
    int dc[4] = {-1, 1, 0, 0};
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int maxArea = 0;

        for (int i=0; i<m; ++i) 
            for (int j=0; j<n; ++j) 
                if (grid[i][j] == 1) 
                    maxArea = max(maxArea, bfs(i, j, grid));

        return maxArea;
    }

private:
    bool inRange(int x, int y) {
        return 0 <= x && x < m && 0 <= y && y < n;
    }

    int bfs(int r, int c, vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        q.push(make_pair(r, c));
        grid[r][c] = 0;
        int area = 0;

        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop(); area++;

            for (int k=0; k<4; ++k) {
                int nx = x + dr[k], ny = y + dc[k];
                if (!inRange(nx, ny) || grid[nx][ny] == 0) continue;
                q.push(make_pair(nx ,ny));
                grid[nx][ny] = 0;
            }
        }

        return area;
    }    
};