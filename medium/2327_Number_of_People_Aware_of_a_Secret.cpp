class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        int MOD = 1'000'000'007;

        vector<vector<int>> dp(n + 1, vector<int>(forget, 0));
        dp[1][0] = 1;  

        for (int i = 2; i <= n; ++i) {
            for (int a = forget - 1; a >= 1; --a) {
                dp[i][a] = dp[i - 1][a - 1];
            }

            long long add = 0;
            for (int a = delay - 1; a <= forget - 2; ++a) {
                if (a >= 0) {
                    add += dp[i - 1][a];
                    if (add >= MOD) add -= MOD;
                }
            }
            dp[i][0] = (int)add;
        }

        long long ans = accumulate(dp[n].begin(), dp[n].end(), 0LL);
        if (ans >= MOD) ans = ans % MOD;
        
        return (int)ans;
    }
};