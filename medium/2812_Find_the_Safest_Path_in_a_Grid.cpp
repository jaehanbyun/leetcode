class Solution {
public:
    vector<pair<int, int>> dxdy = {
        {-1, 0}, {1, 0}, {0, -1}, {0, 1}
    };

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>> dist(n, vector<int>(n, -1));
        queue<pair<int, int>> q;

        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                if (grid[i][j] == 1) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }  
        }

        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            for (auto& d: dxdy) {
                int nx = x + d.first, ny = y + d.second;

                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if (dist[nx][ny] != -1) continue;

                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            } 
        }

        auto check = [&](int v) -> bool {
            vector<vector<bool>> visited(n, vector<bool>(n, false));
            queue<pair<int, int>> bq;
            bq.push({0, 0});
            visited[0][0] = true;

            while (!bq.empty()) {
                auto [x, y] = bq.front(); bq.pop();
                if (x == n - 1 && y == n - 1) return true;

                for (auto& d: dxdy) {
                    int nx = x + d.first, ny = y + d.second;
                    if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if (visited[nx][ny]) continue;
                    if (dist[nx][ny] < v) continue;
                    visited[nx][ny] = true;
                    bq.push({nx, ny});
                }
            }
            return false;
        };

        int lo = 0, hi = dist[0][0], ans = 0;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (check(mid)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return ans;
    }
};