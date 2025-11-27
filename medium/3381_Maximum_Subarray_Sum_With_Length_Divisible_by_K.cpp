class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> pre(n + 1, 0);

        for (int i = 0; i < n; ++i) {
            pre[i + 1] = pre[i] + nums[i];
        }

        long long INF = LLONG_MAX;
        vector<long long> min_pre(k, INF);

        min_pre[0] = 0;

        long long ans = -INF;

        for (int b = 1; b <= n; ++b) {
            int rem = b % k;

            if (min_pre[rem] != INF) {
                long long cand = pre[b] - min_pre[rem];
                if (cand > ans) ans = cand;
            }

            if (pre[b] < min_pre[rem]) {
                min_pre[rem] = pre[b];
            }
        }

        return ans;
    }
};
