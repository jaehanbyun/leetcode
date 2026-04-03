  class Solution {
  public:
      int maximumAmount(vector<vector<int>>& coins) {
          int m = coins.size(), n = coins[0].size();
          const int NEG_INF = INT_MIN;
          vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(3, NEG_INF)));

          // base case
          dp[0][0][0] = coins[0][0];
          dp[0][0][1] = max(coins[0][0], 0); 
          dp[0][0][2] = max(coins[0][0], 0);

          for (int i = 0; i < m; ++i) {
              for (int j = 0; j < n; ++j) {
                  if (i == 0 && j == 0) continue;
                  for (int k = 0; k < 3; ++k) {
                      int best = NEG_INF;
                      if (i > 0) best = max(best, dp[i-1][j][k]);
                      if (j > 0) best = max(best, dp[i][j-1][k]);

                      dp[i][j][k] = best + coins[i][j];

                      if (coins[i][j] < 0 && k > 0) {
                          int best2 = NEG_INF;
                          if (i > 0) best2 = max(best2, dp[i-1][j][k-1]);
                          if (j > 0) best2 = max(best2, dp[i][j-1][k-1]);
                          dp[i][j][k] = max(dp[i][j][k], best2); 
                      }
                  }
              }
          }

          return dp[m-1][n-1][2];
      }
  };