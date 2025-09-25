class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int tSize = triangle.size();
        vector<vector<int>> dp(tSize);
        for (int i = 0; i < tSize; ++i) dp[i].resize(i + 1, 0);

        dp[0][0] = triangle[0][0];
        for (int i = 1; i < tSize; ++i) {
            for (int j = 0; j < i + 1; ++j) {
                if (j == 0) dp[i][j] = dp[i-1][j]+triangle[i][j];
                else if (j == i) dp[i][j] = dp[i-1][j-1]+triangle[i][j];
                else dp[i][j] = triangle[i][j] + min(dp[i-1][j-1], dp[i-1][j]);
            }
        }

        return *min_element(dp[tSize-1].begin(), dp[tSize-1].end());
    }
};