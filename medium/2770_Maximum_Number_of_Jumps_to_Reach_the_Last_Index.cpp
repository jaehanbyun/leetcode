class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<long long> dp(n, LONG_MIN);
        dp[0] = 0;

        for (int i=0; i<n; ++i) {
            for (int j=i+1; j<n; ++j) {
                if (dp[i] != LONG_MIN && abs(nums[j] - nums[i]) <= target) {
                    dp[j] = max(dp[j], dp[i] + 1);
                }
            }
        }
        for (auto& x: dp) {
            cout << x << ' ';
        }

        return dp[n-1] == LONG_MIN ? -1: (int)dp[n-1];
    }
};