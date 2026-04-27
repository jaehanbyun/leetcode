/*
  0
  |  
3-+-1
  |
  2
*/

class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false)); 
        vector<vector<int>> street(7);
        street[1] = {1, 3};
        street[2] = {0, 2};
        street[3] = {2, 3};
        street[4] = {1, 2};
        street[5] = {0, 3};
        street[6] = {0, 1};

        // 0 up, 1 right, 2 down, 3 left
        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, 1, 0, -1};

        function<bool(int, int)> dfs = [&](int x, int y) -> bool {
            if (x == m - 1 && y == n - 1) return true;
            visited[x][y] = true;

            int t = grid[x][y];

            for (int d: street[t]) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                if (visited[nx][ny]) continue;

                int nt = grid[nx][ny];
                int need = (d+2) % 4;

                bool ok = false;
                for (int nd: street[nt]) {
                    if (nd == need) {
                        ok = true;
                        break;
                    }
                }
                if (!ok) continue;
                if (dfs(nx, ny)) return true;
            }

            return false;
        }; 

        return dfs(0, 0);
    }
};
