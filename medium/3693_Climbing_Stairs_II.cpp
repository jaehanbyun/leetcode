class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> c(n+1, 0);
        for (int i=1; i<=n; ++i) {
            c[i] = costs[i-1];
        }

        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        for (int i=0; i<=n; ++i) {
            for (int j=i+1; j<=n && j<=i+3; ++j) {
                dp[j] = min(dp[i] + c[j] + (j - i) * (j - i), dp[j]);
            }
        }

        return dp[n];
    }
};