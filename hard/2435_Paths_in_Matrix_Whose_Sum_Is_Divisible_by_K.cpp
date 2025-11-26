class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        const long long MOD = 1'000'000'000 + 7;
        int m = (int)grid.size(), n = (int)grid[0].size();

         // dp[r][c][rem]: (r, c)까지 왔을 때 합 % k == rem 인 경로 수
        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(k, 0)));
      
        dp[0][0][grid[0][0] % k] = 1;

        pair<int, int> dxdy[] = {{-1, 0}, {0, -1}};

        // first row
        for (int c=1; c<n; ++c) {
            int num = grid[0][c];
            for (int val=0; val<k; ++val) {
                if (dp[0][c-1][val] != 0) {
                    int rem = (val + num) % k;
                    dp[0][c][rem]++;
                }
            }
        }

        // first col
        for (int r=1; r<m; ++r) {
            int num = grid[r][0];
            for (int val=0; val<k; ++val) {
                if (dp[r-1][0][val] != 0) {
                    int rem = (val + num) % k;
                    dp[r][0][rem]++;
                }
            }
        }

        for (int r=1; r<m; ++r) {
            for (int c=1; c<n; ++c) {
                int num = grid[r][c];
                for (int d=0; d<2; ++d) {
                    for (int val=0; val<k; ++val) {
                        if (dp[r+dxdy[d].first][c+dxdy[d].second][val] != 0) {
                            int rem = (num + val) % k;
                            dp[r][c][rem] += dp[r+dxdy[d].first][c+dxdy[d].second][val] % MOD;
                        }
                    }
                }
            }
        }

        return dp[m-1][n-1][0] % MOD;
    }
};