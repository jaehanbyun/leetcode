class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int N = (int)nums.size();
        
        vector<int> dp(N, 0);
        dp[0] = 1;
        for (int i = 1; i < N; ++i) {
            if (nums[i-1] < nums[i]) dp[i] = dp[i-1] + 1;
            else dp[i] = 1;
        }

        for (int s = 0; s + 2 * k - 1 < N; ++s) {
            if (dp[s + k - 1] >= k && dp[s + 2 * k - 1] >= k) return true;
        }

        return false;
    }
};