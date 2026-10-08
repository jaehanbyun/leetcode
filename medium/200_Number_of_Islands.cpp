class Solution {
    int m, n;
    int dr[4] = {0, 0, -1, 1};
    int dc[4] = {-1, 1, 0, 0};

public:
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        
        int island = 0;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (grid[i][j] == '1') {
                    island++;
                    bfs(i, j, grid);
                }
            }
        }
        
        return island;
    }

    bool inRange(int x, int y) {
        return 0 <= x && x < m && 0 <= y && y < n;
    } 

    void bfs(int r, int c, vector<vector<char>>& grid) {
        queue<pair<int, int>> q;
        q.push({r, c});
        grid[r][c] = '0';

        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();

            for (int k=0; k<4; ++k) {
                int nx = x + dr[k], ny = y + dc[k];
                
                if (!inRange(nx, ny) || grid[nx][ny] == '0') continue;

                grid[nx][ny] = '0';
                q.push({nx, ny});
            }
        }
    }
};