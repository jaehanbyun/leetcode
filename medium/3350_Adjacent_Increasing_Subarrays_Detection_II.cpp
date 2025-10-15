class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int N = (int)nums.size();
        if (N < 2) return 0;

        vector<int> forwardDP(N, 1);
        vector<int> backwardDP(N, 1);
        for (int i = 1; i < N; ++i) {
            if (nums[i-1] < nums[i]) forwardDP[i] = forwardDP[i-1] + 1 ;
        }
        for (int i = N - 2; i >= 0; --i) {
            if (nums[i] < nums[i+1]) backwardDP[i] = backwardDP[i+1] + 1;
        }

        int ans = -1e9;
        for (int i = 1; i < N; ++i) {
            ans = max(ans, min(forwardDP[i-1], backwardDP[i]));
        }
    
        return ans;
    }
};
