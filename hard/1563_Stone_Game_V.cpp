class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();

        // prefix[i] = stoneValue[0] ~ stoneValue[i-1]의 합
        vector<long long> prefix(n + 1, 0);
        for (int i=0; i<n; ++i) {
            prefix[i+1] = prefix[i] + stoneValue[i];
        }

        // dp[l][r] = stoneValue[l..r]에서 Alice가 얻을 수 있는 최대 점수
        vector<vector<long long>> dp(n, vector<long long>(n, 0));

        for (int length=2; length<=n; ++length) {
            for (int l=0; l+length<=n; ++l) {
                int r = l + length - 1;

                for (int k=l; k<r; ++k) {
                    long long leftSum = prefix[k+1] - prefix[l];
                    long long rightSum = prefix[r+1] - prefix[k+1];

                    long long candidate;

                    if (leftSum < rightSum) {
                        candidate = leftSum + dp[l][k];
                    } else if (leftSum > rightSum) {
                        candidate = rightSum + dp[k+1][r];
                    } else {
                        candidate = leftSum + max(dp[l][k], dp[k+1][r]);
                    }

                    dp[l][r] = max(dp[l][r], candidate);
                }
            }
        }

        return (int)dp[0][n-1];
    }
};