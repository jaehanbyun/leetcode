class Solution {
  public:
      int minimumDistance(string word) {
          int n = word.size();

          auto dist = [](int a, int b) {
              return abs(a / 6 - b / 6) + abs(a % 6 - b % 6);
          };

          const int INF = 1e9;
          vector<vector<int>> dp(n, vector<int>(26, INF));

          for (int other = 0; other < 26; ++other) dp[0][other] = 0;

          for (int i = 1; i < n; ++i) {
              int cur  = word[i] - 'A';
              int prev = word[i - 1] - 'A';
              int step = dist(prev, cur);

              int best_for_prev = INF;
              for (int other = 0; other < 26; ++other) {
                  best_for_prev = min(best_for_prev, dp[i-1][other] + dist(other, cur));
              }

              for (int other = 0; other < 26; ++other) {
                  dp[i][other] = dp[i-1][other] + step;
              }

              dp[i][prev] = min(dp[i][prev], best_for_prev);
          }

          return *min_element(dp[n-1].begin(), dp[n-1].end());
      }
  };