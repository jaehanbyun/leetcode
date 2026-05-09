class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int layers = min(m, n) / 2;

        for (int layer = 0; layer < layers; ++layer) {
            vector<int> r, c, val;

            int top = layer, left = layer;
            int bottom = m - 1 - layer;
            int right = n - 1 - layer;

            // 위쪽 가장자리
            for (int j = left; j <= right; ++j) {
                r.push_back(top);
                c.push_back(j);
                val.push_back(grid[top][j]);
            }
            // 오른쪽 가장자리
            for (int i = top + 1; i <= bottom; ++i) {
                r.push_back(i);
                c.push_back(right);
                val.push_back(grid[i][right]);
            }
            // 아래쪽 가장자리
            for (int j = right - 1; j >= left; --j) {
                r.push_back(bottom);
                c.push_back(j);
                val.push_back(grid[bottom][j]);
            }
            // 왼쪽 가장자리
            for (int i = bottom - 1; i > top; --i) {
                r.push_back(i);
                c.push_back(left);
                val.push_back(grid[i][left]);
            }

            int total = val.size();
            int kk = k % total;
            if (kk == 0) continue;

            for (int i = 0; i < total; ++i) {
                int from = (i + kk) % total;
                grid[r[i]][c[i]] = val[from];
            }
        }

        return grid;
    }
};
