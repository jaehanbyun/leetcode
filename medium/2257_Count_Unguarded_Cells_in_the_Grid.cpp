class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));
        vector<vector<int>> seen(m, vector<int>(n, 0));
        // if grid == 1 cell is guards, else grid == 2 cell is walls
        for (const auto& g: guards) {
            int x = g[0], y = g[1];
            grid[x][y] = 1;
        }
        for (const auto& w: walls) {
            int x = w[0], y = w[1];
            grid[x][y] = 2;
        }

        // 가로 왼 -> 오
        for (int r = 0; r < m; ++r) {
            bool watching = false;
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 2) watching = false;          
                else if (grid[r][c] == 1) watching = true;      
                else if (watching) seen[r][c] = 1;              
            }
        }
        // 가로 오 -> 왼
        for (int r = 0; r < m; ++r) {
            bool watching = false;
            for (int c = n - 1; c >= 0; --c) {
                if (grid[r][c] == 2) watching = false;
                else if (grid[r][c] == 1) watching = true;
                else if (watching) seen[r][c] = 1;
            }
        }
        // 세로 위 -> 아래
        for (int c = 0; c < n; ++c) {
            bool watching = false;
            for (int r = 0; r < m; ++r) {
                if (grid[r][c] == 2) watching = false;
                else if (grid[r][c] == 1) watching = true;
                else if (watching) seen[r][c] = 1;
            }
        }
        // 세로 아래 -> 위
        for (int c = 0; c < n; ++c) {
            bool watching = false;
            for (int r = m - 1; r >= 0; --r) {
                if (grid[r][c] == 2) watching = false;
                else if (grid[r][c] == 1) watching = true;
                else if (watching) seen[r][c] = 1;
            }
        }

        int ans = 0;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 0 && !seen[r][c]) ++ans;
            }
        }
        return ans;
    }
};