class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        const int MOD = 1e9 + 7;
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<long long>> maxdp(m, vector<long long>(n, 0));
        vector<vector<long long>> mindp(m, vector<long long>(n, 0));

        maxdp[0][0] = mindp[0][0] = grid[0][0];

        for (int j = 1; j < n; ++j) {
            long long val = grid[0][j];
            maxdp[0][j] = maxdp[0][j - 1] * val;
            mindp[0][j] = mindp[0][j - 1] * val;
        }

        for (int i = 1; i < m; ++i) {
            long long val = grid[i][0];
            maxdp[i][0] = maxdp[i - 1][0] * val;
            mindp[i][0] = mindp[i - 1][0] * val;
        }

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                long long val = grid[i][j];

                long long fromTopMax = maxdp[i - 1][j] * val;
                long long fromTopMin = mindp[i - 1][j] * val;

                long long fromLeftMax = maxdp[i][j - 1] * val;
                long long fromLeftMin = mindp[i][j - 1] * val;

                long long mx = max({fromTopMax, fromTopMin, fromLeftMax, fromLeftMin});
                long long mn = min({fromTopMax, fromTopMin, fromLeftMax, fromLeftMin});

                maxdp[i][j] = mx;
                mindp[i][j] = mn;
            }
        }

        long long best = maxdp[m - 1][n - 1];
        if (best < 0) return -1;

        best %= MOD;
        return (int)best;
    }
};