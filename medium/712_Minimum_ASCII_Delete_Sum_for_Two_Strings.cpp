class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = (int)s1.size(), m = (int)s2.size();

        int sum1 = 0, sum2 = 0;
        for (char c : s1) sum1 += (int)c;
        for (char c : s2) sum2 += (int)c;

        vector<int> dp(m + 1, 0);

        for (int i = 1; i <= n; i++) {
            int prevDiag = 0; 
            for (int j = 1; j <= m; j++) {
                int saved = dp[j]; 
                if (s1[i - 1] == s2[j - 1]) {
                    dp[j] = prevDiag + (int)s1[i - 1];
                } else {
                    dp[j] = max(dp[j], dp[j - 1]);
                }
                prevDiag = saved;
            }
        }

        int bestCommon = dp[m];
        return sum1 + sum2 - 2 * bestCommon;
    }
};