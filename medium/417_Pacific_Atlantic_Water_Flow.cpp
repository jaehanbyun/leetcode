void bfs(queue<pair<int, int>>& q, vector<vector<int>>& heights, vector<vector<int>>& vis) {
    int m = heights.size();
    int n = heights[0].size();

    static const int dx[4] = {1, -1, 0, 0};
    static const int dy[4] = {0 ,0 , 1, -1};

    while (q.size() > 0) {
        auto [x, y] = q.front(); q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            if (vis[nx][ny]) continue;
            if (heights[nx][ny] >= heights[x][y]) {
                q.push({nx, ny});
                vis[nx][ny] = 1;
            }
        }
    }
}

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> pac(m, vector<int>(n, 0));
        vector<vector<int>> atl(m, vector<int>(n, 0));

        queue<pair<int, int>> qp, qa;

        for (int c = 0; c < n; ++c) { pac[0][c] = 1; qp.push({0, c}); }
        for (int r = 0; r < m; ++r) { pac[r][0] = 1; qp.push({r, 0}); }

        for (int c = 0; c < n; ++c) { atl[m-1][c] = 1; qa.push({m-1, c}); }
        for (int r = 0; r < m; ++r) { atl[r][n-1] = 1; qa.push({r, n-1}); }

        bfs(qp, heights, pac);
        bfs(qa, heights, atl);

        vector<vector<int>> ans;
        for (int r = 0; r < m; ++r)
            for (int c = 0; c < n; ++c)
                if (pac[r][c] && atl[r][c])
                    ans.push_back({r, c});
        return ans;
    }
};