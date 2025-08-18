class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if (k == 0) return 1.0;

        vector<double> dp(n+1);
        dp[0] = 1;
        double window = 1;

        for (int i = 1; i <= n; i++) {
            dp[i] = window / maxPts;

            if (i < k) window += dp[i];

            if (i >= maxPts && i - maxPts < k) {
                window -= dp[i-maxPts];
            }
        }

        double answer = 0;
        for (int i = k; i <= n; i++) answer += dp[i];

        return answer;
    }
};
