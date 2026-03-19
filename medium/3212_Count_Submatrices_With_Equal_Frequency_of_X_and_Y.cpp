class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> cntX(m+1, vector<int>(n+1, 0));
        vector<vector<int>> sum(m+1, vector<int>(n+1, 0));

        auto val = [](char c) {
            if (c == 'X') return 1;
            if (c == 'Y') return -1;
            return 0;
        };

        for (int i=1; i<=m; ++i) {
            for (int j=1; j<=n; ++j) {
                int v = val(grid[i-1][j-1]);
                sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + v;
                cntX[i][j] = cntX[i-1][j] + cntX[i][j-1] - cntX[i-1][j-1] + (grid[i-1][j-1] == 'X');
            }
        }

        int ans = 0;
        for (int i=1; i<=m; ++i) {
            for (int j=1; j<=n; ++j) {
                if (sum[i][j] == 0 && cntX[i][j] > 0) {
                    ans++;
                }
            }
        }

        return ans;
    }
};