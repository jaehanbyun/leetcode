class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        const int MOD = 1'000'000'007;

        // dp0[i][j] : 0을 i개, 1을 j개 사용했고 마지막이 0인 경우의 수
        // dp1[i][j] : 0을 i개, 1을 j개 사용했고 마지막이 1인 경우의 수
        vector<vector<int>> dp0(zero + 1, vector<int>(one + 1, 0));
        vector<vector<int>> dp1(zero + 1, vector<int>(one + 1, 0));

        for (int i = 0; i <= min(zero, limit); ++i) {
            dp0[i][0] = 1;  
        }
    
        for (int j = 0; j <= min(one, limit); ++j) {
            dp1[0][j] = 1;  
        }

        for (int i = 0; i <= zero; ++i) {
            for (int j = 0; j <= one; ++j) {
                if (i == 0 && j == 0) continue;

                if (i > 0 && j > 0) {
                    long long val = 0;
                    val += dp1[i - 1][j];
                    val += dp0[i - 1][j];

                    if (i > limit) {
                        val -= dp1[i - limit - 1][j];
                    }

                    val %= MOD;
                    if (val < 0) val += MOD;
                    dp0[i][j] = (dp0[i][j] + (int)val) % MOD;
                }

             
                if (i > 0 && j > 0) {
                    long long val = 0;
                    val += dp0[i][j - 1];
                    val += dp1[i][j - 1];
                    
                    if (j > limit) {
                        val -= dp0[i][j - limit - 1];
                    }

                    val %= MOD;
                    if (val < 0) val += MOD;
                    dp1[i][j] = (dp1[i][j] + (int)val) % MOD;
                }
            }
        }

        int ans = dp0[zero][one];
        ans += dp1[zero][one];
        ans %= MOD;
        return ans;
    }
};