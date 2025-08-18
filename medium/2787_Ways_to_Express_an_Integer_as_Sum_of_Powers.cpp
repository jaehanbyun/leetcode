class Solution {
public:
    int numberOfWays(int n, int x) {
        const int MOD = 1'000'000'007;

        auto getPowNum = [&](int a) -> int {
            int r = 1;
            for (int i = 0; i < x; i++) {
                r *= a;
                if (r > n) return n + 1;
            }
            return r;
        };
       
        vector<int> powNum;
        for (int i = 1; ; i++) {
            int tmp = getPowNum(i);
            if (tmp > n) break;
            powNum.push_back(tmp);
        }

        int m = powNum.size();
        vector<std::vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int j = 0; j <= m; j++) dp[0][j] = 1;  

        for (int j = 1; j <= m; j++) {
            int pj = powNum[j - 1];
            for (int k = 1; k <= n; k++) {
                int val = dp[k][j - 1];
                if (pj <= k) {
                    val += dp[k - pj][j - 1];
                    if (val >= MOD) val -= MOD;
                }
                dp[k][j] = val;
            }
        }

        int answers = dp[n][m];
        return answers;
    }
};