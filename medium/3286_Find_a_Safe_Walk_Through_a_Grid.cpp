class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        dist[0][0] = grid[0][0];

        priority_queue<tuple<int, int, int>,
                       vector<tuple<int, int, int>>,
                       greater<>> pq;
        pq.push({dist[0][0], 0, 0});

        vector<vector<int>> dir = {
            {-1, 0}, {1, 0}, {0, -1}, {0, 1}
        };

        while (!pq.empty()) {
            auto [cost, x, y] = pq.top(); pq.pop();

            if (cost > dist[x][y]) continue;

            for (auto& d : dir) {
                int nx = x + d[0], ny = y + d[1];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                int ncost = cost + grid[nx][ny];
                if (ncost < dist[nx][ny]) {
                    dist[nx][ny] = ncost;
                    pq.push({ncost, nx, ny});
                }
            }
        }

        return dist[m-1][n-1] < health;
    }
};
